#目标文件：依赖文件
Target=main
Object=1.o 2.o 3.o

$(Target):$(Object)
	gcc $(Object) -o $(Target)   #编译规则

#隐含规则：编译器会根据1.o自动去找1.c
#1.o:1.c
#	gcc -c 1.c -o 1.o

clean:
	rm *.o $(Target)
