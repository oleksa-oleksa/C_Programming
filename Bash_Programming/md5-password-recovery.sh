
#!/bin/bash
# counting md5sum, saving to var, serching and comparing, print

filename=$1
database=$2
LINES=$(cat $filename)
for line in $LINES; do
    passwordMD=$(echo -n $line | md5sum | cut -d '-' -f 1)
    num=$(grep $passwordMD $database | wc -w)
    echo $num, \"$line\", $passwordMD >> passwords.txt
done          
sort -g -r passwords.txt
 
rm passwords.txt
