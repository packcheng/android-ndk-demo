#!/bin/bash
echo 将当前目录下所有后缀为.sh的文件添加到压缩包
for i in `find . -name "*.sh"`
do
	`tar -czf all.taz $i`
done
