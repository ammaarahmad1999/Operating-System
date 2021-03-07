#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>


int prime(int x)
{
   	if(x<=1) 
      	return 0;
   	for(int i=2; i*i<=x; i++)
   	{
        if(x%i==0) 
            return 0;
   	}
   	return 1;
}


int main()
{
  
	int fd0[2],fd1[2];
  	if(pipe(fd0)==-1)
		printf("Can't send infos\n");
	if(pipe(fd1)==-1)
		printf("Can't send infos\n");
	pid_t PID=fork();
 	if(PID==0)
  	{
  		printf("In parent process\n");
        	printf("Enter length of Fibonacci array : ");
        	int n;
        	scanf("%d",&n);
        	int fib[n+1];
        	fib[0]=0;
        	fib[1]=1;
        	for(int i=2;i<=n;i++) 
        		fib[i]=fib[i-1]+fib[i-2];
        
        	//send the n to parent process
        
        	close(fd1[0]);
        	write(fd1[1],&n,sizeof(n));
        	close(fd1[1]);
        
        	//send the fib array to parent process
        	close(fd0[0]);
        	write(fd0[1],&fib,sizeof(fib));
        	close(fd0[1]);
  	}
  	else 
  	{
  		wait(NULL);
  		printf("In child process\n");
  		//receive n from child
  		int n;
        close(fd1[1]);
        read(fd1[0],&n,sizeof(n));
        close(fd1[0]);
    	
        	//receive fibonacci array from child
  		int fib[n+1];
        close(fd0[1]);
        read(fd0[0],&fib,sizeof(fib));
        close(fd0[0]);
        
        printf("Fibonacci series upto n=%d is\n",n);
        for(int i=0;i<=n;i++) 
       		printf("%d ",fib[i]);
       	printf("\nThe prime numbers in this series are\n");
        for(int i=0;i<=n;i++)
        {
       		if(prime(fib[i])==0) 
       			continue;
       		printf("index = %d, number= %d\n",i,fib[i]); 
       	}
  	}
 	return 0;
}
