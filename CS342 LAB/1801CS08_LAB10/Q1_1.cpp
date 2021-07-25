#include <bits/stdc++.h>

using namespace std;

// Structure for a page
struct Page 
{
    int last_used;
    int time_inserted;
    int position;
    int page_num;
};

/* Comparator for FIFO Set */
struct fifo_compare 
{
    bool operator()(Page* p1, Page* p2) const {
        return p1 -> time_inserted < p2 -> time_inserted;
    }
};


/* Function to print initial message */
void initialize(vector<int> page_order, int f, Page pages[]) 
{
    for (int i = 0; i < 99; i++) 
    {
        pages[i].page_num = i + 1;
        pages[i].position = -1;
        pages[i].last_used = -1;
        pages[i].time_inserted = -1;
    }
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


/* 	Function to change page properties 
	If time_inserted and position are -1 then
	make no change to respective fields	*/
void updatePage(Page* page, int time_inserted, int position, int last_used) 
{
	page -> last_used = last_used;
    if (time_inserted != -1) 
    	page -> time_inserted = time_inserted;
    if (position != -1) 
    	page -> position = position;
    return;
}

/*	Function to simulate FIFO page replacement */
void fifo(int f, vector<int> page_order) 
{
    vector<int> frame;
    set<Page*, fifo_compare> S;
    Page pages[99];
    int time = 0, page_faults = 0;
    int n = page_order.size();

    initialize(page_order, f, pages);
    printFrames(frame, f, time);

    for (int i = 0; i < n; i++) 
    {
        time++;
        Page* page = &pages[page_order[i] - 1];
        // If page is not in the current frames
        if (S.find(page) == S.end()) 
        {
            page_faults++;
            // If frames filled are less than max frames available
            if (S.size() < f) 
            {
                updatePage(page, time, frame.size(), time);
                // Insert into next frame
                frame.push_back(page -> page_num);
                S.insert(page);
            }
            // If all frames are already occupied
            else 
            {
                updatePage(page, time, (*S.begin()) -> position, time);
                // Replace the First Inserted frame with current frame
                frame[page -> position] = page -> page_num;
                S.erase(S.begin());
                S.insert(page);
            }
        }
        // If page found in current frames, leave them as is
        // Last use time can be updated
        else 
        	updatePage(page, -1, -1, time);
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
            if (page == -1)		// Terminate page input if -1 encountered
            	break;
            else 
                page_order.push_back(page);
        }
        printf("-------------------------------------------\n");
        printf("TRY %d:\n",try_num);
        fifo(f, page_order);
        printf("-------------------------------------------\n");
        page_order.clear();
    }
}