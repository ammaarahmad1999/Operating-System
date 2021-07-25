#include <bits/stdc++.h>
using namespace std;
void lru(int page_order[], int k, int p)			//LRU Algorithm
{
	list <int> l;
	vector<int>fault;
	for (int i=0; i<p; i++)
	{
		int x = page_order[i];
		auto it = find(l.begin(), l.end(), x);		//Checking if page is present in current frame
		if(it!=l.end())
		{
			l.remove(*it);
			l.push_back(x);
			continue;
		}
		if(l.size()==k)
			l.pop_front();
		l.push_back(x);
		fault.push_back(x);
	}
	cout<<"LRU Page faults"<<endl;
	for (int i=0; i<fault.size(); i++)
		cout<<fault[i]<<" ";
	cout<<endl;
}
void fifo(int page_order[], int k, int p)			//FIFO Algorithm
{
	list <int> l;
	vector<int>fault;
	for (int i=0; i<p; i++)
	{
		int x = page_order[i];
		if(find(l.begin(), l.end(), x)!=l.end())	//Checking if page is present in current frame
			continue;
		if(l.size()<k)
			l.push_back(x);
		else
		{
			l.pop_front();
			l.push_back(x);
		}
		fault.push_back(x);
	}
	cout<<"FIFO Page faults"<<endl;
	for (int i=0; i<fault.size(); i++)
		cout<<fault[i]<<" ";
	cout<<endl;
}
void algo(int page_order[], int k, int p)			//My Algorithm
{
	int s1 = max(5,p/20);
	int s2 = max(25,p/5);
	list<int>l1,l2,l3;
	map<int,int>M;
	set<int>s;
	vector<int>fault;
	for (int i=0; i<p; i++)
	{
		int x = page_order[i];
		M[x]++;
		if(s.count(x))								//If page already present in frame 
		{

		}
		else if(s.size()<k)							//If frame is partially filled
		{
			fault.push_back(x);
			s.insert(x);
		}	
		else										//If frame is completely filled
		{
			int z;
			if(!l3.empty())
			{
				z=l3.front();
				l3.pop_front();
				M.erase(z);
			}
			else if(!l1.empty())
			{
				z=l1.front();
				l1.pop_front();
			}
			else
			{
				z=l2.front();
				l2.pop_front();
			}
			s.erase(z);
			s.insert(x);
			fault.push_back(x);
		}
		if(M[x]==1)									//Updating the 3 priority lists								
			l1.push_back(x);
		else if(M[x]<s1)
		{
			l1.remove(x);
			l1.push_back(x);
		}
		else if(M[x]==s1)
		{
			l1.remove(x);
			l2.push_back(x);
		}
		else if(M[x]<s2)
		{
			l2.remove(x);
			l2.push_back(x);
		}
		else if(M[x]==s2)
		{
			l2.remove(x);
			l3.push_back(x);
		}
		else
		{
			l3.remove(x);
			l3.push_back(x);
		}
	}
	cout<<"My Algorithm Page faults"<<endl;
	for (int i=0; i<fault.size(); i++)
		cout<<fault[i]<<" ";
	cout<<endl;
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int k,p;
		cin>>k>>p;										//Number of frames and Number of Page requests
		int page_order[p];
		for(int i=0; i<p; i++)
			cin>>page_order[i];
		clock_t start, end;
		start = clock();
		algo(page_order, k, p);
		end = clock();
		double t1=double(end - start) / double(CLOCKS_PER_SEC);
		start = clock();
		lru(page_order, k, p);
		end = clock();
		double t2=double(end - start) / double(CLOCKS_PER_SEC);
		start = clock();
		fifo(page_order, k, p);
		end = clock();
		double t3=double(end - start) / double(CLOCKS_PER_SEC);
		cout<<t1<<"\t"<<t2<<"\t"<<t3<<endl;
	}
}