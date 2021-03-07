#!/bin/bash
#Author: Ammaar Ahmad
#Roll No: 1801CS08

decimal_to_binary()
{
	num=$1
	i=0				#loop variable
        bin=""				#binary form of number	
        while [ $i -lt 64 ]		#loop for converting decimal to binary
        do
                if [ $(($num % 2)) == 1 ]
                then
                       bin+="1"
                else
                	bin+="0"
                fi
                num=$(($num/2))
                i=$(($i+1))		#increment of loop variable
        done
        echo $bin			#returning binary form
}
xor()
{
       num1=$1		#first number
       num2=$2		#second number
       power=1		#power of 2
       ans=0		#final xor
       i=0		#loop variable
       bin1=$(decimal_to_binary $(($num1)))	#binary form of first number	
       bin2=$(decimal_to_binary $(($num2)))	#binary form of second number
       i=0
       while [ $i -lt 64 ]		#loop for finding xor between 2 binary numbers
       do
        	b1="${bin1:$i:1}"	# ith bit of first number
        	b2="${bin2:$i:1}"	# ith bit of second number
        	if [ $b1 -ne $b2 ]	# xor operation
               then
               	ans=$(( $ans+$power ))
               fi
               power=$(($power * 2))	#power of 2
               i=$(($i + 1))		#increment of loop variable
       done
       echo $ans
}
start=`date +%s%N`
xor $1 $2
end=`date +%s%N`
time_taken=$(($end - $start))
echo Execution time was $time_taken nanoseconds
