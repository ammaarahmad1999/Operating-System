#!/bin/bash

#Author: Ammaar Ahmad
#Roll No: 1801CS08
#Searching element in an array
num=$1			#Number of elements of an array
declare -a A  		#Array declaration
shift 1		#Shifting pointer
i=0			#Array index
while [ $i -lt $num ]	#Loop to store elements in an array
do 
	A[$i]=$1
	i=$(($i+1))
	shift 1
done
S=$1			#Search element
Y=$num			#flag variable
i=0			#loop variable
while [ $i -lt $num ]	#till end of loop	
do
	if [ $((A[$i])) == $S ]	#if found then store index and break
	then
		Y=$i
		break
	fi
	i=$(($i+1))
done
if [ $Y -lt $num ]			#if index < N then print statement below
then	
	echo Search found at index $Y of searched item $S
else
	echo Error: Element not found
fi
