#!/bin/bash
cal
cal | sort -n -r 
cal | cut -d " " -f 6
cal | cut -d " " -f 1 | wc -l
cal | sort
