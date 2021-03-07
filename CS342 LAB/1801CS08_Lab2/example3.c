//Author: Ammaar Ahmad
//Roll No: 1801CS08

#include<stdio.h>
#include <time.h>
void decimal_to_binary(char val[64], long long int n);
long long int xor(long long int a, long long int b);
void decimal_to_binary(char val[64], long long int n)
{
    	int i=0;
	while ( i<=64 )
	{
    		int r=n%2;
    		val[i]=r+48;
    		n=n/2;
    		i++;
	}
}
long long int xor_function(long long int a, long long int b)
{
	char ar[64];
	decimal_to_binary(ar,a);
     	char br[64];
     	decimal_to_binary(br,b);
     	int i=0;
     	long long int power = 1;
     	long long int ans=0;
     	while(i<=64)
     	{
     		if(ar[i]!=br[i])
     			ans = ans + power;
     		power = power*2;
     		i++;	
     	}
     	return ans;
}
int main()
{
	long long int n,m;
	scanf("%lld %lld",&n,&m);
	clock_t tic = clock();
	long long int ans = xor_function(n,m);
	printf("%lld\n",ans);
	clock_t toc = clock();
	printf("Execution time was %f nanoseconds\n", 1000000000*(float)(toc - tic) / 		CLOCKS_PER_SEC);
}
