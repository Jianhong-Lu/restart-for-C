#!/bin/bash

for ((i=0;i<10;i++))
do
	echo "this is $i"
done

for i in 1 2 3 4 5
do
	echo $i
done

#echo "hello" > xx

echo "开始读文件"
while read i
do
	echo $i
done < test.txt
