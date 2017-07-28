#!/bin/bash
sum=

summe() {
	sum=0
	for i in $*; do #as separate strings
		sum=$(( $sum + $i))
	done
}

summe $*
echo $sum
