#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int compare (const void * a, const void * b) 
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
	int num, head, request;
	printf("Enter the head position: ");
	scanf("%d",&head);
	printf("Enter the number of cylinders: ");
	scanf("%d",&num);
	printf("Enter the number of requests: ");
	scanf("%d",&request);
	int disk[request];
	for (int i=0; i<request; i++)
		scanf("%d",&disk[i]);
	qsort(disk, request, sizeof(int), compare);
	int min = disk[0];
	int max = disk[request - 1];
	int ans=0;
	printf("Head Movement\n");
	if(head-min < max-head)
	{
		ans = abs(head-min) + max-min;
		printf("%d",head);
		for (int i=request-1; i>=0; i--)
		{
			if(disk[i]<head)
				printf("---->%d",disk[i]);
		}
		for (int i=0; i<request; i++)
		{
			if(disk[i]>head)
				printf("---->%d",disk[i]);
		}
	}
	else
	{
		ans = abs(max-head) + max-min;
		printf("%d",head);
		for (int i=0; i<request; i++)
		{
			if(disk[i]>head)
				printf("---->%d",disk[i]);
		}
		for (int i=request-1; i>=0; i--)
		{
			if(disk[i]<head)
				printf("---->%d",disk[i]);
		}
	}
	int seek = ans*5;
	printf("\nTotal Head Movement: %d\n",ans);
	printf("Seek Time: %d\n",seek);
}
