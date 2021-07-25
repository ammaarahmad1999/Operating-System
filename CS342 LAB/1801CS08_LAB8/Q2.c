#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 

int sum=0;
int prime[10001];
pthread_t tid[4]; 
pthread_mutex_t lock;

void SieveOfEratosthenes() 				//Sieve of Erasthosthenes to find prime No from 1 to 10000
{  
    for (int p=2; p<=10000; p++)
    	prime[p] = 1;
    prime[0]=prime[1]=0;
    for (int p=2; p*p<=10000; p++) 
    { 
        if (prime[p] == 1) 
        { 
            for (int i=p*p; i<=10000; i+=p) 
                prime[i] = 0; 
        } 
    } 
} 

void* f(void * arg) 					//Thread function to sum the prime numbers
{ 
    int id = *( (int* ) arg);
    pthread_mutex_lock(&lock);			//Requesting to acquire Mutex Lock
    for(int i=id*2500 + 1; i<=(id+1)*2500; i++)	//Sum the prime number in this thread
      if(prime[i])
         sum += i;
    pthread_mutex_unlock(&lock); 			//Releasing Mutex Lock
  
    return NULL; 
} 

int main(void) 
{ 
    SieveOfEratosthenes();				//Check number is prime or not by this function call
    int error; 
  
    if (pthread_mutex_init(&lock, NULL) != 0) 	//Initializing Mutex Lock
    { 
        printf("\n mutex init has failed\n"); 
        return 1; 
    } 
  
    for (int i=0; i<4; i++)				//Creating 4 Threads
    { 
        int* arg = (int *) malloc(sizeof(* arg));
        *arg = i;
        error = pthread_create(&(tid[i]), NULL, &f, (void *)arg ); 
        if (error != 0) 
            printf("\nThread can't be created :[%s]", strerror(error)); 
    } 
  
    pthread_join(tid[0], NULL); 			//Joining 4 Threads
    pthread_join(tid[1], NULL); 
    pthread_join(tid[2], NULL); 
    pthread_join(tid[3], NULL); 
    pthread_mutex_destroy(&lock); 			//Destroying Mutex Locks
      
    printf("Prime sum till 10000: %d\n",sum);
    return 0; 
} 
