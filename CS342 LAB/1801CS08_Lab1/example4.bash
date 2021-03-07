#!/bin/bash

#Author: Ammaar Ahmad
#Roll No: 1801CS08
directory_path=$1
filename_pattern=$2
new_filename=$3
count=0
#Checking if atleast 3 inputs exists
if [ $3 ]
then
	cd $directory_path
	for files in *
	do
		if [[ $files == *"$filename_pattern"* ]]
		then
			count=$(($count+1))
			ext="${files##*.}"   # preserving extension of file
        		mv $files $new_filename"_"$count"."$ext  # renaming
        	fi
	done
else
	echo "Give input as directory_path <space> filename_pattern <space> new_filename"
fi
