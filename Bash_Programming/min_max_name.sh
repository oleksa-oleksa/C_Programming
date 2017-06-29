#!/bin/bash


for line in $(cat /etc/passwd | cut -d ":" -f 1); do
	length=`echo $line | wc -m`
	echo $length $line >> users.txt 
done

for name in $(cat ./users.txt | sort -n | cut -d ' ' -f 2); do
echo $name
done

rm users.txt


