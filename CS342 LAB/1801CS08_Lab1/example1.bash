#!/bin/bash

#Author: Ammaar Ahmad
#Roll No: 1801CS08
#Storing input number in number  variable
number=$1

#Initializing reverse number as 0

reverse=0

#Checking if the input exists
if [ $number ]
then
	if [ $number -le 0 ]	#checking if number is less than 0
	then
		number=$((-1*$number))		#absolute value
	fi

	while [ $number != 0 ]	#while number = 0	
	do 
	     reverse=$(($reverse*10 + $number%10))	#reversing digits
	     number=$(($number/10))			#number divides by 10
	done

	if [ $1 -le 0 ]		# if negative number
	then
		reverse=$((-1*$reverse))	#adding sign
	fi
	echo $reverse			
else
	echo error			# error
fi
