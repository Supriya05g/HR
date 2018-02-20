// https://www.hackerrank.com/challenges/waiter/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

void get_first_n_prime_numbers(int x, vector<int> &list)
{
	int i=2,j,count=0;
	// cout<<"Prime numbers are: ";
	while(i && count < x)
	{
		bool prime=true;
		for(j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				prime=false;
				break;
			}
		}
		if(prime)
		{
			// cout<<i<<"\t";
			count++;
			list.push_back(i);
		}
		i++;
	}
	// cout<<"\n";
}

void print_stack(stack<int> &st)
{
	while(!st.empty())
	{
		cout<<st.top()<<"\n";
		st.pop();
	}
}

int main() {
	int n,i,q,ele,prime;
	cin>>n>>q;
	vector<stack<int>>B;
	vector<int> primes;
	get_first_n_prime_numbers(q,primes);
	stack<int> a,aq;
	for(i=0;i<n;i++)
	{
		cin>>ele;
		a.push(ele);
	}
	for(i=0;i<q;i++)
	{
		stack<int> b;
		prime=primes[i];
		if(i%2==0)
		{
			//Push from a to aq
			while(!a.empty())
			{
				ele=a.top();
				a.pop();
				if(ele%prime==0)
					b.push(ele);
				else
					aq.push(ele);
			}
		}
		else
		{
			//Push from aq to a
			while(!aq.empty())
			{
				ele=aq.top();
				aq.pop();
				if(ele%prime==0)
					b.push(ele);
				else
					a.push(ele);
			}
		}
		B.push_back(b);
	}	
	while(!B.empty())
	{
		print_stack(B.front());
		B.erase(B.begin());
	}
	if(a.empty())
		print_stack(aq);
	else
		print_stack(a);
    return 0;
}
