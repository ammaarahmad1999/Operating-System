#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int num, head, request, max=0, min=200;
	printf("Enter the head position: ");
	scanf("%d",&head);
	printf("Enter the number of cylinders: ");
	scanf("%d",&num);
	printf("Enter the number of requests: ");
	scanf("%d",&request);
	int disk[num];
	for (int i=0; i<request; i++)
	{
		scanf("%d",&disk[i]);
		if(max<disk[i])
			max=disk[i];
		if(min>disk[i])
			min=disk[i];
	}
	int ans=0;
	if(head-min < max-head)
		ans = abs(head-min) + max-min;
	else
		ans = abs(max-head) + max-min;
	int seek = ans*5;
	printf("Total Head Movement: %d\n",ans);
	printf("Seek Time: %d\n",seek);
}
