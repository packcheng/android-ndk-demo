#!/bin/bash

while read line
do
	echo $line
done<`pwd`/file1.txt
