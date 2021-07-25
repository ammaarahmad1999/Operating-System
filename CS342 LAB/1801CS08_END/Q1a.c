#include <stdio.h>
int main()
{
	int n,c,r;
	printf("Enter the number of resources: ");
	scanf("%d",&r);
	printf("Enter the requirement for each process: ");
	scanf("%d",&c);
	n = (r-1)/(c-1);
	printf("Maximum Number of process such that no deadlock occurs = %d\n",n);
}