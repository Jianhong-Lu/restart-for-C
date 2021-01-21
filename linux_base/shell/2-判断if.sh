#!/bin/bash

num=$1
path=$2

if [ -z $num ]; then    #判断参数的长度是否为0
	echo "请输入一个数字"
	exit
fi

if [ -z $path ]; then
	echo "请输入一个路径"
	exit
fi

if [ $num -lt 10 ]; then
	echo "小于 10"
elif [ $num -gt 10 ];then
	echo "大于 10"
else
	echo "等于 10"
fi

if [ -d $path ]; then   #路径为文件夹则成立
	echo "路径是文件夹"
elif [ -f $path ]; then
	echo "路径是文件"
fi
