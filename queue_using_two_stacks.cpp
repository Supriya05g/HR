// https://www.hackerrank.com/challenges/queue-using-two-stacks/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
	stack<unsigned long int> inbox,outbox;
	unsigned long int ele;
	int n,type;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>type;
		if(type==1)
		{
			cin>>ele;
			inbox.push(ele);
		}
		else 
		{
			if(outbox.empty())
			{
				while(!inbox.empty())
				{
					ele=inbox.top();
					inbox.pop();
					outbox.push(ele);
				}
			}
			if(type==2)
				outbox.pop();
			else
				cout<<outbox.top();
		}
	}
    return 0;
}
