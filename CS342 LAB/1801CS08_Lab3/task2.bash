#!/bin/bash
#Author: Ammaar Ahmad
#Roll No: 1801CS08
# to find sum of prime number
PrimeNoLessThan()		#function to find sum of primes less than n
{
    if [ $1 -le 1 ]		#base condition
    then
    	echo 0
    elif [ $1 == 2 ]		#another base condition
    then
    	echo $1
    else			#if number > 2
        i=2
        check=0
        sqrt=$(bc <<< "scale=0; sqrt($1)")
        while [ $i -le $sqrt ]	# finding if prime or not
        do
            rem=$(($1 % $i))
            if [ $rem == 0 ]
            then
                check=1
                break
            fi
            i=$(($i + 1))
        done
        cur=$(PrimeNoLessThan $(($1-1)))	#sum of prime from 1 to number-1
        if [ $check == 0 ]			# if prime then add current number
        then
        	cur=$(($cur+$1))
        fi
        echo $cur				#return sum of primes less than equal to number
    fi

}
# recursive function to find factorial
fact()						#function to find factorial recursively
{
    if [ $1 -le 1 ];
    then
        echo 1
    else
        last=$(fact $(( $1 - 1 )))
        fact=$(( $1 * last ))
        echo $fact
    fi
}
last=$(fact $(( $1 - 1 )))			#factorial of number-1
fact=$(( $1 * last ))				#factorial of number
sum=$(PrimeNoLessThan $1)			#sum of primes less than equal to number
fact=$(($fact*$sum))				#answer
echo $fact
