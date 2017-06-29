#!/bin/bash
cat /proc/cpuinfo | grep "model name"
cat /proc/cpuinfo | grep "cpu MHz"

echo ""

FIRST=$(free -h | head -n 1)
echo $FIRST | cut -d " " -f 1

LAST=$(free -h | head -n 2 | tail -n 1)
echo $LAST | cut -d " " -f 2

echo ""

FIRST=$(free -h | head -n 1)
echo $FIRST | cut -d " " -f 3

LAST=$(free -h | head -n 2 | tail -n 1)
echo $LAST | cut -d " " -f 4

echo ""
df -h | head -n 4 | tail -n 1

echo ""
echo -n "Active Processes:"
ps ax | wc -l

echo ""
echo -n "Operation system:"
uname -a | cut -d " " -f 1
echo -n "Kernel version: "
uname -r

