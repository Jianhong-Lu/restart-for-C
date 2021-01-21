#!/bin/bash

s="hello"

echo "helloworld"
echo "this is bash" >> test.txt
echo $s
echo ${s}
echo "i want output ${s}"

#脚本使用命令行参数
echo $1
echo $2
echo $3
#输出命令行参数个数
echo $#    
echo $*
