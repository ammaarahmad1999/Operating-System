#!/bin/bash

#Author: Ammaar Ahmad
#Roll No: 1801CS08

#Storing input number in left right variable
left=$1
right=$2
#Checking if the input exists
if [ $2 ]
then
	if [ $left -lt $right ]		# if left less than right
	then
		while [ $left -le $right ]	# while left<=right
		do 
		     echo -n "$left "		# printing number and space	
		     left=$(($left+1))		#increment left
		done
		echo 				#next line
	else
		echo "error: Incorrect range"	#incorrect range error
	fi
else
	echo "error: Please enter 2 inputs <number1> <number2>"	# 2 numbers required
fi
