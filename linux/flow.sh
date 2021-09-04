#!/bin/bash

echo 流程控制测试

for i in `seq 1 10`
do
	echo 遍历了数据：$i
done

echo 累加器
a=0
for((i=0;i<=100;i++))
do
	a=`expr $i + $a`
done
echo 累加结果：$a

b=0
while((b<=100))
do
	b=`expr $b + 1`
done
echo b的结果是：$b
