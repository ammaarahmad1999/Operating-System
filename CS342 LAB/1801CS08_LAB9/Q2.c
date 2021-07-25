#include<stdio.h> 
int main()
{
	int i,j,np,nr;
	printf("Enter the no of process: ");
  	scanf("%d",&np);
  	printf("Enter the no of resources: ");
  	scanf("%d",&nr);
	int allocation_matrix[np][nr];				//Allocation Matrix
	int request_matrix[np][nr];					//Request Matrix
	int available_matrix[nr];					//Available Matrix	
	int r[nr];									//Total No. of each Resource					
	int w[nr];									//Work Array
	int finish[np];							//Finished Process Array

  	for(i=0;i<nr;i++)
  	{
    	printf("Total Amount of the Resource R%d: ",i+1);
    	scanf("%d",&r[i]);
    }
    
    printf("\nEnter the request matrix:\n");			//Request Matrix
	for(i=0;i<np;i++)
    	for(j=0;j<nr;j++)
    		scanf("%d",&request_matrix[i][j]);
    
    printf("\nEnter the allocation matrix:\n");			//Allocation Matrix
    for(i=0;i<np;i++)
    	for(j=0;j<nr;j++)
    		scanf("%d",&allocation_matrix[i][j]);

    /*Available Resource calculation*/
    for(j=0;j<nr;j++)									//Available Resource and Work Array
    {
    	available_matrix[j]=r[j];
    	for(i=0;i<np;i++)
    		available_matrix[j]-=allocation_matrix[i][j];
    	w[j]=available_matrix[j];
    }

	//Completed the processes with no request initially
	int cnt=0;
	for(i=0;i<np;i++)									//Finished Process
	{
		finish[i] = 0;
		int req = 0;
		for (int j=0; j<nr; j++)
			req += request_matrix[i][j];
		if (req == 0)
		{
			finish[i]=1;
			cnt++;										//Count of no. of processes completed
		}
	}	
	int prev_cnt = cnt; 								//Previously Completed Process
	int deadlock = 0;									//Deadlock
	while (cnt < np)						
	{
		for (int i=0; i<np; i++)						//Iterating over process
		{
			if(finish[i]==0)							//If Process is not completed
			{
				int canbeprocessed=1;					//Initially Assumed it can be processed
				for(j=0;j<nr;j++)
        		{
          			if(request_matrix[i][j] > w[j])		//If available Resource is less than requested
          			{
           				canbeprocessed=0;				//It can't be processed
            			break;
          			}
        		}
        		if(canbeprocessed==1)					//If it can be processed
        		{
         			finish[i]=1;						//Complete the process
          			for(j=0;j<nr;j++)
            			w[j]+=allocation_matrix[i][j];	//Release the acquired resources
          			cnt++;								//Increment the No. of process completed
        		}
			}
		}
		if(cnt==prev_cnt)								//If no increment in completed process
		{
			deadlock = 1;								//There is a deadlock
      		break;						
		}
      	prev_cnt = cnt;									//Update the completed process
	}
	if(deadlock)
    	printf("\nDeadlock detected\n");
  	else
    	printf("\nNo Deadlock possible, System in Safe State \n");
}
