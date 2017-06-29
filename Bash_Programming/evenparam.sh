#!/bin/bash
let n=$#
let i=1

if [ $((n%2)) -eq 0 ]
then
 while [ $i -lt $n ];
  do
    j=$((i+1))
    echo "${!i} = ${!j}"
    let i+=2
  done
# If error
else
 echo "Err: Odd amount of parameters" >&2
 exit 1
fi
