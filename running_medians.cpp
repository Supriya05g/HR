// https://www.hackerrank.com/challenges/find-the-running-median/problem

#include<bits/stdc++.h>

using namespace std;

int main()
{
	priority_queue<int>maxheap;
	priority_queue<int,vector<int>,greater<int>> minheap;
	int n,i,ele;
	float median;
	cin>>n;
	cin>>ele;
	median=ele;
	maxheap.push(ele);
	cout<<setprecision(1)<<fixed;
	cout<<median<<"\n";
	while(cin>>ele)
	{
		//First add the ele to one of the heaps
		if(ele>=(int) median)
		{
			minheap.push(ele);
			if(minheap.size()-maxheap.size()>1)
			{
				ele=minheap.top();
				minheap.pop();
				maxheap.push(ele);
			}
		}
		else 
		{
			maxheap.push(ele);
			if(maxheap.size()-minheap.size()>1)
			{
				ele=maxheap.top();
				maxheap.pop();
				minheap.push(ele);
			}

		}
		//Now get the median
		if(minheap.size()==maxheap.size())
			median=(minheap.top()+maxheap.top())/2.0;
		else if(minheap.size()>maxheap.size())
			median=minheap.top();
		else
			median=maxheap.top();

		cout<<median<<"\n";
	}
}
