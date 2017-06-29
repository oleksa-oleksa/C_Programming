#!/bin/bash


while [ true ]; do

echo -n $1, $2, $3 ": "
read answer

if [ $answer == $2 ]
 then
  exit 0
fi
 
if [ $answer == $3 ]
 then  
  exit 1

fi
done 
