#include <stdio.h>
int main()
{
	int n,r;
	printf("Enter the number of process: ");
	scanf("%d",&n);
	printf("Enter the requirement for each process:\n");
	int c[n];
	int sum=0;
	for (int i=0; i<n; i++)
	{
		scanf("%d",&c[i]);
		sum = sum + c[i];
	}
	sum = sum-n;
	printf("Maximum Number of resources such that deadlock  can occur = %d\n",sum);
	sum++;
	printf("Minimum Number of resources such that it is deadlock free = %d\n",sum);
}
