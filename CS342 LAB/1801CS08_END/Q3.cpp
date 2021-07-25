#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
struct process
{
	char j;					//Job ID
	int id;					//Process ID
	int at;					//Arrival Time
	int bt;					//Burst Time
	int st;					//Start Time
	int et;					//End Time	
	int rt;					//Remaining Time
	char s;					//Status 
};
struct execute
{
	int id;
	int rt;
	int tq;
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
	int n,t; 
	int tq1, tq2;							//Time Quantum for each process
	cin>>tq1>>tq2>>n;			
	process a[n];							//Each Process Data
	vector<int>ans;							//order of process completion array
	queue<process>q;									
	for (int i=0; i<n; i++)					//Input Loop
	{
		a[i].id=i;
		cin>>a[i].j>>a[i].at>>a[i].bt;
		a[i].st=a[i].et=0;
		a[i].rt=a[i].bt;
		a[i].s = 'N';
	}
	cout<<endl<<"Enter the time instance for status"<<endl;
	cin>>t;
	sort(a, a+n, compare);						//Sorting Proecss according to Arrival Time
	for (int i=0; i<n; i++)						//Changing Temporary ID to index
		a[i].id=i;
	int time = 0;								//Initial Time = 0
	int swt=0, stat=0;							//Cummulative Waiting Time, Turnaround Time
	int i=0;				
	execute p1, p2;
	p1.id = p2.id = -1;
	p1.rt = p2.rt = 0;
	p1.tq = tq1;
	p2.tq = tq2;
	while(1)
	{
		while(i<n && a[i].at<=time)
		{
			a[i].s = 'W';
			q.push(a[i]);
			i++;
		}
		if (p1.id>=0 && p1.rt == 0)				//If process in 1st processor has completed
		{
			p1.tq = tq1;
			a[p1.id].rt = p1.rt;
			a[p1.id].et = time;
			a[p1.id].s = 'C';
			p1.id = -1;
		}
		if (p2.id>=0 && p2.rt == 0)				//If process in 2nd processor has completed
		{
			p2.tq = tq2;
			a[p2.id].rt = p2.rt;
			a[p2.id].et = time;
			a[p2.id].s = 'C';
			p2.id = -1;
		}
		if(p1.tq > 0 && p1.rt > 0)
			a[p1.id].rt = p1.rt;
		if(p2.tq > 0 && p2.rt > 0)
			a[p2.id].rt = p2.rt;
		if(p1.tq == 0 && p1.rt > 0)				//Processor 1
		{
			a[p1.id].rt = p1.rt;
			a[p1.id].s = 'W';
			q.push(a[p1.id]);
			p1.id = -1;
		}
		if(p2.tq == 0 && p2.rt > 0)				//Processor 2
		{
			a[p2.id].rt = p2.rt;
			a[p2.id].s = 'W';
			q.push(a[p2.id]);
			p2.id = -1;
		}
		if(i<n && q.empty() && p1.id == -1 && p2.id == -1)					
		//If no process in queue increase time to next process arriving
		{
			time = a[i].at;
			q.push(a[i]);
			i++;
		}
		if(p1.id == -1 && !q.empty())
		{
			p1.id = q.front().id;
			p1.rt = q.front().rt;
			p1.tq = tq1;
			q.pop();
			a[p1.id].s = 'E';
			if(a[p1.id].rt == a[p1.id].bt)
				a[p1.id].st = time;
		}
		if(p2.id == -1 && !q.empty())
		{
			p2.id = q.front().id;
			p2.rt = q.front().rt;
			p2.tq = tq2;
			q.pop();
			a[p2.id].s = 'E';
			if(a[p2.id].rt == a[p2.id].bt)
				a[p2.id].st = time;
		}
		time++;
		if(p1.id>=0)
		{
			p1.rt--;
			p1.tq--;
		}
		if(p2.id>=0)
		{
			p2.rt--;
			p2.tq--;
		}
		if(time==t || (i==n && q.empty() && p1.id == -1 && p2.id == -1))
			break;
	}	
	for (int i=0; i<n; i++)
	{
		if(a[i].at>time)
			break;
		if(a[i].bt == a[i].rt)
			cout<<a[i].j<<"\t"<<a[i].at<<"\t"<<a[i].bt<<"\t"<<"\t"<<"\t"<<a[i].s<<endl;
		else if(a[i].s != 'C')
			cout<<a[i].j<<"\t"<<a[i].at<<"\t"<<a[i].bt<<"\t"<<a[i].st<<"\t"<<"\t"<<a[i].s<<endl;
		else
			cout<<a[i].j<<"\t"<<a[i].at<<"\t"<<a[i].bt<<"\t"<<a[i].st<<"\t"<<a[i].et<<"\t"<<a[i].s<<endl;
	}
}