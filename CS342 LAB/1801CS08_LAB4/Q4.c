#include <stdlib.h> 
#include <stdio.h>
#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h>  

void bubble_sort(int arr[],int n)		//function to sort
{
	for(int i=0;i<n-1;i++)
    {
    	for(int j=0;j<n-i-1;j++)
       	{
        	if(arr[j]<arr[j+1])
           	{
               	int tmp=arr[j];
               	arr[j]=arr[j+1];
              	arr[j+1]=tmp;
           	}
       	}
   	}
}

int main(int argc, char * argv[]) 
{   
    if(argc != 3)				// Reqiured inputs 2 filemame
    {
        printf("Wrong Input format\n");
        printf("Please enter file exectuable name followed by 2 file's name \n");
        exit(2);
    }
    if(fork() > 0) 				// Creating first child
    {     
        wait(NULL);          	//Wait for child process to complete
        if(fork() > 0) 			// Another child process
        {    
            wait(NULL);       	//Waiting for completion of 2nd child process
            printf("Third child process : %d to display content sorted of file2 in reverse.\n", getpid());
            printf("Parent of 3rd child process is : %d \n\n", getppid());
            FILE *fp1 = fopen(argv[2], "r");	//reading from 2nd file
            int num;
            int i = 0;
            int a[100000];
            int flag = 0;
            while(fscanf(fp1, "%d", &num) == 1) //Reading numbers
            {
                a[i++] = num;
            }
            int len = i;
            bubble_sort(a,len);					//Descending Order sort
            printf("The file2 in desending sorted order is :\n");
            for(i = 0; i < len; i++) 			//Display the contents
            { 
                printf("%d ", a[i]);
            }
            printf("\n\n");						
            fclose(fp1);
        }
        else 									//2nd Child Process
        {                    
            printf("Second child process : %d to display content of file2.\n", getpid());
            printf("Parent of 2nd child process is : %d.\n\n", getppid());
            printf("The content of file2 are: \n");
            FILE *fp1 = fopen(argv[2], "r");;		//Reading from 2nd file
            int num;
            while(fscanf(fp1, "%d", &num) == 1) 	//Display the contents of 2nd file
            {
                printf("%d ", num);				
            }
            printf("\n\n");
            fclose(fp1);
        }
    }
    else 											//1st child process
    {
        printf("First child process : %d to copy files.\n", getpid());
        printf("Parent of 1st child process is : %d.\n\n", getppid());
        FILE *fp1 = fopen(argv[1], "r");			//1st file
        FILE *fp2 = fopen(argv[2], "w");          	//2nd file
        int num;
        while(fscanf(fp1, "%d",&num) == 1) 			//Copying contents from 1st file to 2nd file
        {
            fprintf(fp2, "%d ", num);
        }
        fclose(fp1);
        fclose(fp2);
    }
    return 0;
}
