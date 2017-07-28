#!/bin/bash
let a=3
echo $[a+2] # a is still 3
let b='test'
echo $[b+a]
let c=a*b
echo $c

#######
FOO=42
echo $FOO
FOO=$FOO.23
echo $FOO

BAR=$(date +%T)
echo $BAR

set | grep FOO
set | grep BAR
env | grep BAR

export BAR
env | grep BAR
unset BAR
echo $BAR
