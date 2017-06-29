#!/bin/bash
mkdir backup 2>/dev/null

for file in $(ls *$1);
 do
   echo -n "Do you want to backup " + $file + "? y/n: "
  read userInput
  if [ $userInput == 'y' ]
   then
     cp -i $file backup/$file
     echo $file + " done."
    else
     echo $file + "... backup skipped"
   fi
 done
