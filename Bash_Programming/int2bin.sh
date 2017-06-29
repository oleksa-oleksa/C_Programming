#!/bin/bash
decimal=$1
binary=""
while [ $decimal -ne 0 ]; do
binary=$(( $decimal % 2))$binary
decimal=$[decimal / 2]
done
echo $1 " = " $binary
