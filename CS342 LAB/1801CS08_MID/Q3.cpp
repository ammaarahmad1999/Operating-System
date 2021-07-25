#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
struct process
{
	int id;					//Process ID
	int at;					//Arrival Time
	int pt;					//Priority 
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
	int n;									//Number of Process
	cin>>n;				
	process a[n];							//Each Process Data
	vector<int>ans;							//order of process completion array
	set <vector<int>> s;					//Set for sorting in desired manner
	for (int i=0; i<n; i++)					//Input Loop
	{
		a[i].id=i;
		cin>>a[i].at>>a[i].pt>>a[i].bt;
		a[i].ct=a[i].wt=a[i].tat=0;
	}
	sort(a, a+n, compare);					//Sorting Proecss according to Arrival Time
	int time = 0;							//Initial Time = 0
	int swt=0, stat=0;						//Cummulative Waiting Time, Turnaround Time
	int i=0;				
	while(i<n)								//Loop
	{
		while(i<n && a[i].at<=time)			// If process has arrived insert in set
		{
			s.insert({-a[i].pt, a[i].at, a[i].id, a[i].bt});
			i++;
		}
		if(i<n && s.empty())				// If no process in set increase time to first process arriving
		{
			time = a[i].at;
			s.insert({-a[i].pt, a[i].at, a[i].id, a[i].bt});
			i++;
		}
		vector<int> b=*s.begin();
		int index = b[2];
		int rt = b[3];					
		s.erase(s.begin());						//Deleting current instance of this process
		time = time+1;						//Time Increment by 1(Preemptive)
		if(rt == 1)							//If remaining time = 1 => process is completed
		{
			//Calculating Various Time of Completed Process					
			a[index].ct = time;	
			a[index].tat = time - a[index].at;		
			a[index].wt = a[index].tat - a[index].bt;
			swt+=a[index].wt;
			stat+=a[index].tat;
			ans.push_back(index);
		}
		else
		{
			b[3] = b[3] - 1;
			s.insert(b);					//If remaining time > 1 => re insert the process with decrement in remaining time
		}
	}
	while(!s.empty())
	{
		vector<int> b=*s.begin();					
		int index = b[2];
		int rt = b[3];
		s.erase(s.begin());						//Deleting current instance of this process
		time = time+rt;						//Time Increment by 1(Preemptive)
		a[index].ct = time;
		a[index].tat = time - a[index].at;
		a[index].wt = a[index].tat - a[index].bt;
		swt+=a[index].wt;
		stat+=a[index].tat;
		ans.push_back(index);
			//If remaining time > 1 => re insert the process with decrement in remaining time
	}
	float num = n;							//Number of Process				
	float awt = swt/num;					//Average Waiting Time
	float atat = stat/num;					//Average Turnaround Time	
	cout<<fixed<<setprecision(2)<<"Average Waiting Time: "<<awt<<endl;
	cout<<fixed<<setprecision(2)<<"Average Turnaround Time: "<<atat<<endl;
	cout<<"Order of Completion of process:"<<endl;
	for (int i=0; i<ans.size(); i++)		//Printing Order of completion of Process
		cout<<"P"<<ans[i]+1<<" ";			
	cout<<endl;
}