#!/bin/bash
let n=$#
if [ $n -ne 2 ]
then
 echo "Err: Incorrect parameter call" >&2
 exit 1
fi

for file in *;
 do
  let len=$(echo -n $file | wc -m)
  if [ $len -ge $1 ]; then
   if [ $len -lt $2 ]
    then
     echo $file
    fi
  fi
 done





