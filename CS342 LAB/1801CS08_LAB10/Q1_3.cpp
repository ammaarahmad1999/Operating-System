#include <bits/stdc++.h>

using namespace std;

/* Function to print initial message */
void initialize(vector<int> page_order, int f) 
{
    printf("\nFIFO:\n");
    for (int i=0; i<page_order.size(); i++) 
    {
        int x = page_order[i];
        printf("%d ",x);
    }
    printf("\nFrame content at each time step t\n");
    for (int i = 0; i < f; i++) 
        printf("F%d\t",i+1);
    printf("\n");
    return;
}
/* Function to print frame contents at any instant of time */
void printFrames(vector<int> frame, int f, int time) 
{
    int n = frame.size();
    for (int i = 0; i < f; i++) 
    {
        if (i < n) 
            printf("%d\t",frame[i]);
        else 
            printf("X\t");
    }
    printf("at t = %d\n",time);
    return;
}

/*	Function to simulate Optimal page replacement */
void optimal(int f, vector<int> page_order) {
    vector<int> frame;
    int time = 0, page_faults = 0;
    int n = page_order.size();

    initialize(page_order, f);
    printFrames(frame, f, time);

    for (int i = 0; i < n; i++) 
    {
        time++;
        // If page is not in the current frames
        if (find(frame.begin(), frame.end(), page_order[i]) == frame.end()) 
        {
            page_faults++;
            // If frames filled are less than max frames available
            // Insert into next frame
            if (frame.size() < f) 
            	frame.push_back(page_order[i]);
            // If all frames are already occupied
            else 
            {
            	// Find the page that will be out of use the longest
                int index = 0;
                int longest_wait = 0;
                for (int j = 0; j < frame.size(); j++) 
                {
                    int wait = INT_MAX;
                    for (int k = i + 1; k < n; k++) 
                    {
                        if (page_order[k] == frame[j]) 
                        {
                            wait = k - i;
                            break;
                        }
                    }
                    if (wait > longest_wait) 
                    {
                        longest_wait = wait;
                        index = j;
                    }
                }
                // Replace the page unneeded the longest by current page
                frame[index] = page_order[i];
            }
        }
        // Do nothing and proceed to printing frames if page is in current frames
        printFrames(frame, f, time);
    }
    printf("\n#Page Faults: %d\n",page_faults);
    return;
}

int main() 
{
    // File Pointer to open pages.txt input file
    FILE *fp;
    fp = fopen("pages.txt", "r");
    // If unable to open file
    if (fp == NULL) 
    {
        printf("[-] Error opening file 'pages.txt'. Check the file and try again.\n");
        return 0;
    }
    int f, page, try_num = 0;;    
    vector<int> page_order;
    // While input is available,
    // take input of total number of frames
    // followed by the page requirement order
    while (fscanf(fp,"%d",&f) == 1) 
    {
        ++try_num;
        while (fscanf(fp,"%d",&page) == 1) 
        {
            if (page == -1)     // Terminate page input if -1 encountered
                break;
            else 
                page_order.push_back(page);
        }
        printf("-------------------------------------------\n");
        printf("TRY %d:\n",try_num);
        optimal(f, page_order);
        printf("-------------------------------------------\n");
        page_order.clear();
    }
}