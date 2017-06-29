#!/bin/bash

for file in $(ls $1*); 
 do 

  NEWNAME=$(echo $file | sed s/$1/$2/)
  echo $NEWNAME
  #mv "$file" $2${file#$1}

 done
