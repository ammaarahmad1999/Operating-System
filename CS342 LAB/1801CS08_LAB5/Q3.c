#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h> 		//	required for cbrt() function.
#include <unistd.h>

void * thread_function(void *param)
{
	int i;
	double *result = malloc(sizeof(double)*1000);	// create array to store results.
	for(i=0; i < 1000; i++)
		result[i] = cbrt((double)i);	//	compute the answer using cbrt() library function.
	return (void *)result;	//	return the result.
}

int main()
{
	pthread_t threadID;
	void *exit_status;
	double	*result;
	int i;
	
	printf("\n\nComputation under process. Please wait...\n\n");
	pthread_create(&threadID,NULL,thread_function,NULL);
	pthread_join(threadID,&exit_status);
	result = (double *) exit_status;
	
	for(i=0; i<1000; i++)
		printf("\ncbrt(%d) = %lf",i,result[i]);
	free(result);	
	printf("\n\n");
	return 0;
}
