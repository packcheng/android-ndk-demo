#!/bin/bash
echo "hello world"
echo PWD=$PWD
echo 当前Shell脚本的名字：$0
echo 第一个参数：$1
echo 第二个参数：$2

#-----------------
echo 本次执行状态如下:
if(($?));then
 echo 本次执行失败
else
 echo 本次执行成功
fi

echo 外部传递参数内容：$*
echo 外部传递参数个数：$#
