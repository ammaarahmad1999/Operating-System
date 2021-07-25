#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>
int prime(int x)                //Checking if number is prime
{
   	if(x<=1) 
      	return 0;
   	for(int i=3; i*i<=x; i++)
   	{
        if(x%i==0) 
            return 0;
   	}
   	return 1;
}
int main(int argc, char **argv)
{	
	if(argc < 2)
		printf("Running command ./Q2 <number>");
    int n=atoi(argv[1]);
	int fd0[2],fd1[2], fd2[2];           //Pipes
    if(pipe(fd0)==-1)
		printf("Can't send infos\n");
	if(pipe(fd1)==-1)
		printf("Can't send infos\n");
    if(pipe(fd2)==-1)
        printf("Can't send infos\n");
	pid_t PID=fork();
    if (PID == 0)                           //1st Child Process
    {
        if(fork())                          //1st Child
        {
            float sum = 0;  
            for (int i=2; i<=n; i+=2)       //Sum of even harmonic terms
                sum = sum + 1.0/i;
            close(fd0[0]);
            write(fd0[1],&sum,sizeof(sum)); //Writing on Pipes
            close(fd0[1]);
        }
        else                                //2nd Child
        {
            float sum = 0;
            for (int i=3; i<=n; i+=2)       //Sum of prime harmonic terms
            {
                if(prime(i))
                    sum = sum + 1.0/i;
                if(i%6==1)
                    i = i+2;
            }
            close(fd1[0]);
            write(fd1[1],&sum,sizeof(sum)); //Writing on Pipes
            close(fd1[1]);
        }
    }
    else                                    //Parent
    {
        wait(NULL);                         //Waiting for 1st child is terminate
        if(fork())                          //Parent Process
        {
            wait(NULL);
            float s1, s2, s3;
            close(fd0[1]);
            read(fd0[0],&s2,sizeof(s2));
            close(fd0[0]);
            close(fd1[1]);
            read(fd1[0],&s3,sizeof(s3));
            close(fd1[0]);
            close(fd2[1]);
            read(fd2[0],&s1,sizeof(s1));
            close(fd2[0]);
            float ans = s1 + s3 - s2;       //Sum of the harmonic series
            printf("Final sum of the series upto %d terms is: %f\n",n,ans);
        }
        else                                //3rd Child
        {
            float sum = 1;
            for (int i=9; i<=n; i+=2)       //Sum of odd non-prime harmonic series
            {
                if(prime(i)==0)
                    sum = sum + 1.0/i;
            }
            close(fd2[0]);
            write(fd2[1],&sum,sizeof(sum)); //Writing in pipes
            close(fd2[1]);
        }
    }
}
