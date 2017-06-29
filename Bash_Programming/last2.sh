#!/bin/bash
amount=$#
prev=$(echo $[$amount-1])
echo -n ${!prev} " "
echo ${!amount}
