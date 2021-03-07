#!/bin/bash
#Author: Ammaar Ahmad
#Roll No: 1801CS08
#While taking input put ur string within double or single quotes

string=$1				#Taking the string input 
len=${#string}				#Calculating the length of the string

#Flag variables
flag1=0
flag2=0
flag3=0

i=0					#loop iterator

#Comparing the length with 7
if [ $len -ge 7 ]
then
    while [ $i -lt $len ]		#iteration through password
    do
        char=${string:$i:1}
        #Checking if the character is a alphabet....1st 2nd and 3rd if statement
        if [ $char \> 'a' ] && [ $char \< 'z' ]
        then
             flag1=1
        elif [ $char \> 'A' ] && [ $char \< 'Z' ]
        then 
             flag1=1
        elif [ $char \= 'A' ] || [ $char \= 'Z' ] || [ $char \= 'a' ] || [ $char \= 'z' ]
        then
             flag1=1
        #Checking if the character is a integer....4th and 5th if statement
        elif [ $char \> '0' ] && [ $char \< '9' ]
        then 
            	flag2=1
        elif [ $char \= '0' ] || [ $char \= '9' ]
        then
            	flag2=1
        #Checking if the character is a special character....6th if statement
        elif [ $char \= '/' ] || [ $char \= '(' ] || [ $char \= ')' ] || [ $char \= '<' ] || [ $char \= '>' ] || [ $char \= '?' ]
        then
            	flag3=1

        fi 
        i=$(($i+1))
    done
    #If all the if conditions satisfy
    if [ $flag1 == 1 ] && [ $flag2 == 1 ] && [ $flag3 == 1 ];
    then
        echo Valid Password
    else
        echo Invalid Password
    fi
else
    echo Invalid Password 
fi
