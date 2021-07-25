#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
struct process
{
	int id;					//Process ID
	int at;					//Arrival Time
	int bt;					//Burst Time
	int ct;					//Completion Time
	int wt;					//Waiting Time	
	int tat;				//Turnaround Time
};

bool compare(process a, process b)			//Comparison for sorting
{
	if(a.at!=b.at)							
		return a.at<b.at;					//increasing order of Arrival Time
	else
		return a.id<b.id;					//Tiebreaker - Process ID
}
int main()
{
	int n; int tq;							//Number of Process and Time Quantum
	cin>>n>>tq;			
	process a[n];							//Each Process Data
	vector<int>ans;							//order of process completion array
	queue<pair<int,int>>q;									
	for (int i=0; i<n; i++)					//Input Loop
	{
		a[i].id=i;
		cin>>a[i].at>>a[i].bt;
		a[i].ct=a[i].wt=a[i].tat=0;
	}
	sort(a, a+n, compare);						//Sorting Proecss according to Arrival Time
	int time = 0;								//Initial Time = 0
	int swt=0, stat=0;							//Cummulative Waiting Time, Turnaround Time
	int i=0, index=-1, rt=0;					
	while(i<n)									//Loop
	{
		while(i<n && a[i].at<=time)				// If process has arrived insert in queue
		{
			q.push({a[i].id, a[i].bt});
			i++;
		}
		if(rt > 0)										// Last executed process is push back to ready queue if not completed
			q.push({index, rt});
		if(i<n && q.empty())							//If no process in queue increase time to next process arriving
		{
			time = a[i].at;
			q.push({a[i].id, a[i].bt});
			i++;
		}
		index = q.front().first;
		rt = q.front().second;			
		q.pop();										//Deleting current instance of this process
		if(rt <= tq)									//If remaining time <= Time Quantum => process is completed
		{
			//Calculating Various Time of Completed Process					
			time = time + rt;
			rt = 0;
			a[index].ct = time;	
			a[index].tat = time - a[index].at;		
			a[index].wt = a[index].tat - a[index].bt;
			swt+=a[index].wt;
			stat+=a[index].tat;
			ans.push_back(index);
		}
		else
		{
			time = time + tq; 
			rt = rt - tq;					
		}
	}
	if(rt > 0)										// Last executed process is push back to ready queue if not completed
		q.push({index, rt});
	while(!q.empty())
	{				
		index = q.front().first;
		rt = q.front().second;					
		q.pop();									//Deleting current instance of this process
		if(rt <= tq)								//If remaining time <= Time Quantum => process is completed
		{
			//Calculating Various Time of Completed Process					
			time = time + rt;
			rt = 0;
			a[index].ct = time;	
			a[index].tat = time - a[index].at;		
			a[index].wt = a[index].tat - a[index].bt;
			swt+=a[index].wt;
			stat+=a[index].tat;
			ans.push_back(index);
		}
		else
		{
			time = time + tq; 
			rt = rt - tq;		
			q.push({index, rt});					// Last executed process is push back to ready queue if not completed
		}
	}
	float num = n;							//Number of Process				
	float awt = swt/num;					//Average Waiting Time
	float atat = stat/num;					//Average Turnaround Time	
	cout<<fixed<<setprecision(2)<<"Avg_WT = "<<awt<<" Avg_TAT = "<<atat<<endl;
	for (int i=0; i<ans.size(); i++)		//Printing Order of completion of Process
		cout<<"P"<<ans[i]+1<<" ";			
	cout<<endl;
}