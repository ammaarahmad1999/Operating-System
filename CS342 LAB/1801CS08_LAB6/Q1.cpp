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
	int n;									//Number of Process
	cin>>n;				
	process a[n];							//Each Process Data
	set<pair<int,int>>s;					//Set for sorting in desired manner
	for (int i=0; i<n; i++)					//Input Loop
	{
		a[i].id=i+1;
		cin>>a[i].at>>a[i].bt;
		a[i].ct=a[i].wt=a[i].tat=0;
	}
	sort(a, a+n, compare);					//Sorting Proecss according to Arrival Time
	int time = 0;							//Initial Time = 0
	int swt=0, stat=0;						//Cummulative Waiting Time, Turnaround Time				
	for (int i=0; i<n; i++)					//First Come First Serve Implementation
	{
		a[i].ct=max(time,a[i].at)+a[i].bt;	
		a[i].tat=a[i].ct-a[i].at;
		a[i].wt=a[i].tat-a[i].bt;
		swt+=a[i].wt;
		stat+=a[i].tat;
		time=a[i].ct;
	}
	//for (int i=0; i<n; i++)
	//	cout<<a[i].id<<"\t"<<a[i].at<<"\t"<<a[i].bt<<"\t"<<a[i].ct<<"\t"<<a[i].wt<<"\t"<<a[i].tat<<endl;
	float num = n;							//Number of Process				
	float awt = swt/num;					//Average Waiting Time
	float atat = stat/num;					//Average Turnaround Time	
	cout<<fixed<<setprecision(2)<<awt<<" "<<atat<<endl;
	for (int i=0; i<n; i++)					//Printing Order of completion of Process
		cout<<"P"<<a[i].id<<" ";			
	cout<<endl;
}