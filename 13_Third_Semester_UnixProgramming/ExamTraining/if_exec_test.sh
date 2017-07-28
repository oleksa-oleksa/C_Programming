#!/bin/bash
if $@ ; then
	echo Command \"$@\" succeded
else
	echo Command \"$@\" failed
fi
