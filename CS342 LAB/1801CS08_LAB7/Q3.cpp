#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
struct process
{
	int id;					//Process ID
	int at;					//Arrival Time
	int bt;					//Burst Time
	int qn;					//Queue Number(System:1 or User:2)
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
	int n; int t;							//Number of Process and Time Quantum
	cin>>n>>t;			
	int tq1 = 4, tq2 = 3;
	process a[n];							//Each Process Data
	vector<int>ans;							//order of process completion array
	queue<pair<int,int>>system;				//System Priority Queue
	queue<pair<int,int>>user;				//User Priority Queue
	for (int i=0; i<n; i++)					//Input Loop
	{
		a[i].id=i;
		cin>>a[i].at>>a[i].bt>>a[i].qn;
		a[i].ct=a[i].wt=a[i].tat=0;
	}
	sort(a, a+n, compare);						//Sorting Proecss according to Arrival Time
	int time = 0;								//Initial Time = 0
	int swt=0, stat=0;							//Cummulative Waiting Time, Turnaround Time
	int i=0, index=-1, rt=0, qn=0;					
	while(i<n)									//Loop
	{
		while(i<n && a[i].at<=time)				// If process has arrived insert in queue
		{
			if(a[i].qn == 1)
				system.push({a[i].id, a[i].bt});
			else
				user.push({a[i].id, a[i].bt});
			i++;
		}
		if(rt > 0)										// Last executed process is push back to ready queue if not completed
		{
			if(qn==1)
				system.push({index, rt});
			else
				user.push({index,rt});
		}
		if(i<n && system.empty() && user.empty())		//If no process in queue increase time to next process arriving
		{
			time = a[i].at;
			if(a[i].qn == 1)
				system.push({a[i].id, a[i].bt});
			else
				user.push({a[i].id, a[i].bt});
			i++;
		}
		if (!system.empty())
		{
			index = system.front().first;
			rt = system.front().second;	
			qn = 1;				
			system.pop();								//Deleting current instance of this process
			if(rt <= tq1)								//If remaining time <= Time Quantum => process is completed
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
				time = time + tq1; 
				rt = rt - tq1;					
			}
		}
		else
		{
			index = user.front().first;
			rt = user.front().second;	
			qn = 2;				
			user.pop();									//Deleting current instance of this process
			if(rt <= tq2)								//If remaining time <= Time Quantum => process is completed
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
				time = time + tq2; 
				rt = rt - tq2;					
			}
		}
	}
	if(rt > 0)											// Last executed process is push back to ready queue if not completed
	{
		if(qn==1)
			system.push({index, rt});
		else
			user.push({index,rt});
	}
	while(!system.empty())
	{				
		index = system.front().first;
		rt = system.front().second;			
		system.pop();									//Deleting current instance of this process
		if(rt <= tq1)									//If remaining time <= Time Quantum => process is completed
		{
			//Calculating Various Time of Completed Process					
			time = time + rt;
			a[index].ct = time;	
			a[index].tat = time - a[index].at;		
			a[index].wt = a[index].tat - a[index].bt;
			swt+=a[index].wt;
			stat+=a[index].tat;
			ans.push_back(index);
		}
		else
		{
			time = time + tq1; 
			rt = rt - tq1;		
			system.push({index,rt});					// Last executed process is push back to ready queue if not completed
		}
	}
	while(!user.empty())
	{
		index = user.front().first;
		rt = user.front().second;	
		user.pop();										//Deleting current instance of this process
		if(rt <= tq2)									//If remaining time <= Time Quantum => process is completed
		{
			//Calculating Various Time of Completed Process					
			time = time + rt;
			a[index].ct = time;	
			a[index].tat = time - a[index].at;		
			a[index].wt = a[index].tat - a[index].bt;
			swt+=a[index].wt;
			stat+=a[index].tat;
			ans.push_back(index);
		}
		else
		{
			time = time + tq2; 
			rt = rt - tq2;	
			user.push({index,rt});						//Last executed process is push back to ready queue if not completed
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