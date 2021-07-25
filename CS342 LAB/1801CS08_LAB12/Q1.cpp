#include <bits/stdc++.h>
using namespace std;
int num, request, mx=0, mn=INT_MAX;
vector<int> disk;
void plot(vector<int> &coord_x, vector<int> &coord_y, string name)
{
	string algo = name;
	int cnt_points = coord_x.size(), cnt_commands = 3;
	name =  "\"" + name + "\"";
	name = "set title " + name;
	const char * title = name.c_str();
	char const * commands[10000];
    commands[0] = title;
    commands[1] = "set xlabel \"Seek time (ms)\"";
    commands[2] = "set ylabel \"Cylinders Number\"";
    for (int i=0; i < cnt_points; i++)
    {
    	string tmp= "\"" + to_string(  (int)coord_x[i]) + " " + to_string((int)coord_y[i]) + "\"" ;
    	tmp = "set label " + tmp + " at " +  to_string( coord_x[i]) + "," + to_string(coord_y[i]);
    	char * label = new char [tmp.length()+1];
    	strcpy (label, tmp.c_str());
    	commands[ cnt_commands] = label;
    	cnt_commands++;
    }
    string filename = algo+".temp";
    const char * file = filename.c_str();
    string command = "plot '"+filename+"' with linespoints";
    commands[cnt_commands++] = command.c_str();
    FILE * temp = fopen(file, "w");
    FILE * gnu_plot_pipe = popen ("gnuplot -persistent", "w");
    for (int i=0; i < cnt_points; i++)
    	fprintf(temp, "%d %d\n", coord_x[i], coord_y[i]); //Write the data to a temporary file
    
    for (int i=0; i < cnt_commands; i++)
    	fprintf(gnu_plot_pipe, "%s \n", commands[i]); //Send commands to gnuplot one by one.
  	fclose(temp);
  	fclose(gnu_plot_pipe);
}
int FCFS(int head)					//FCFS disk Algorithm
{
	int THM = 0;
	vector<int>order;
	vector<int>seek;
	for (int i=0; i<request; i++)
	{
		order.push_back(disk[i]);
		THM += abs(disk[i]-head);
		seek.push_back(THM*5);
		head = disk[i];
	}
	printf("---------------FCFS--------------------\n");
	int seek_time = THM*5;
	printf("Total Head Movement: %d\n",THM);
	printf("Seek Time: %d\n",seek_time);
	for (int i=0; i<order.size()-1; i++)
		printf("%d---->",order[i]);
	printf("%d\n",order.back());
	plot(seek, order, "FCFS");
	return seek_time;
}
int SCAN(int head)					//SCAN disk Algorithm
{
	int THM = 0;
	vector<int>order;
	vector<int>seek;
	sort(disk.begin(), disk.end());
	int k=0;
	while(disk[k]<=head)
		k++;
	for (int i=k-1; i>=0; i--)
	{
		order.push_back(disk[i]);
		THM += abs(disk[i]-head);
		seek.push_back(THM*5);
		head = disk[i];
	}
	THM += head;
	head = 0;
	for (int i=k; i<request; i++)
	{
		order.push_back(disk[i]);
		THM += abs(disk[i]-head);
		seek.push_back(THM*5);
		head = disk[i];
	}
	printf("---------------SCAN--------------------\n");
	int seek_time = THM*5;
	printf("Total Head Movement: %d\n",THM);
	printf("Seek Time: %d\n",seek_time);
	for (int i=0; i<order.size()-1; i++)
		printf("%d---->",order[i]);
	printf("%d\n",order.back());
	plot(seek, order, "SCAN");
	return seek_time;
}
int CSCAN(int head)				//CSCAN disk Algorithm
{
	int THM = 0;
	vector<int>order;
	vector<int>seek;
	sort(disk.begin(), disk.end());
	int k=0;
	while(disk[k]<=head)
		k++;
	for (int i=k-1; i>=0; i--)
	{
		order.push_back(disk[i]);
		THM += abs(disk[i]-head);
		seek.push_back(THM*5);
		head = disk[i];
	}
	THM += head;
	head = 0;
	THM += num-1;
	head = num-1;
	for (int i=request-1; i>=k; i--)
	{
		order.push_back(disk[i]);
		THM += abs(disk[i]-head);
		seek.push_back(THM*5);
		head = disk[i];
	}
	printf("---------------C-SCAN------------------\n");
	int seek_time = THM*5;
	printf("Total Head Movement: %d\n",THM);
	printf("Seek Time: %d\n",seek_time);
	for (int i=0; i<order.size()-1; i++)
		printf("%d---->",order[i]);
	printf("%d\n",order.back());
	plot(seek, order, "CSCAN");
	return seek_time;
}
int SSTF(int head)				//SSTF disk Algorithm
{
	int THM = 0;
	vector<int>order;
	vector<int>seek;
	sort(disk.begin(), disk.end());
	int k=0;
	while(disk[k]<=head)
		k++;
	stack<int>less;
	stack<int>greater;
	for(int i=0; i<k; i++)
		less.push(disk[i]);
	for(int i=request-1; i>=k; i--)
		greater.push(disk[i]);
	while(!less.empty() && !greater.empty())
	{
		int left = less.top();
		int right = greater.top();
		if(head-left < right-head)
		{
			order.push_back(left);
			less.pop();
			THM += abs(left-head);
			seek.push_back(THM*5);
			head = left;
		}
		else
		{
			order.push_back(right);
			greater.pop();
			THM += abs(right-head);
			seek.push_back(THM*5);
			head = right;
		}
	}
	while(!less.empty())
	{
		int left = less.top();
		order.push_back(left);
		less.pop();
		THM += abs(left-head);
		seek.push_back(THM*5);
		head = left;
	}
	while(!greater.empty())
	{
		int right = greater.top();
		order.push_back(right);
		greater.pop();
		THM += abs(right-head);
		seek.push_back(THM*5);
		head = right;
	}
	printf("---------------SSTF--------------------\n");
	int seek_time = THM*5;
	printf("Total Head Movement: %d\n",THM);
	printf("Seek Time: %d\n",seek_time);
	for (int i=0; i<order.size()-1; i++)
		printf("%d---->",order[i]);
	printf("%d\n",order.back());
	plot(seek, order, "SSTF");
	return seek_time;
}
int main()
{
	int head;
	printf("Enter the head position: ");
	scanf("%d",&head);
	printf("Enter the number of cylinders: ");
	scanf("%d",&num);
	printf("Enter the number of requests: ");
	scanf("%d",&request);
	for (int i=0; i<request; i++)
	{
		int x;
		scanf("%d",&x);
		disk.push_back(x);
		if(mx<x)
			mx=x;
		if(mn>x)
			mn=x;
	}
	set<pair<int, string>>s;
	s.insert({FCFS(head),"FCFS"});
	s.insert({SCAN(head),"SCAN"});
	s.insert({CSCAN(head),"CSCAN"});
	s.insert({SSTF(head),"SSTF"});
	printf("---------------------------------------\n");
	printf("Sorted Order of Algorithms\n");
	for (auto it=s.begin(); it!=s.end(); it++)
		cout<<it->second<<":"<<it->first<<endl;
}
