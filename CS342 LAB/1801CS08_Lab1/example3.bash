#!/bin/bash

#Author: Ammaar Ahmad
#Roll No: 1801CS08
#Storing input filename and limit
file_name=$1
limit=$2
count=0
#Checking if atleast 2 input exists
if [ $2 ]  
then
	if [ -f "$file_name" ]   #checking if file exists or not
	then
		while IFS= read -r line	#reading line by line
		do
			count=$(($count+1))    #counting the file
		done < "$file_name"		
		echo Total number of lines = $count #total number of lines
		if [ $count -lt $limit ]	#comparing number of lines with limit
		then
			rm $file_name		#deleting filename
			echo "$filename deleted"	#
		else
			echo "Lines are greater equal to $limit. So, not deleted."	
		fi
	else
		echo "error: $file_name doesnot exist" #FIle does not exist
	fi
else
	echo "Give input as filename <space> limit"	#Give Proper input
fi
