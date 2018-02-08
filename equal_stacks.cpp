#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	vector<long int> stack1,stack2,stack3,temp;
	long int n1,n2,n3,h1=0,h2=0,h3=0,ele,smallest;
	cin>>n1>>n2>>n3;
	for(int i=0;i<n1;i++)
	{
		cin>>ele;
		temp.push_back(ele);
	}
	for(int i=0;i<n1;i++)
	{
		h1+=temp.back();
		temp.pop_back();
		stack1.push_back(h1);
	}
	for(int i=0;i<n2;i++)
	{
		cin>>ele;
		temp.push_back(ele);
	}
	for(int i=0;i<n2;i++)
	{
		h2+=temp.back();
		temp.pop_back();
		stack2.push_back(h2);
	}
	for(int i=0;i<n3;i++)
	{
		cin>>ele;
		temp.push_back(ele);
	}
	for(int i=0;i<n3;i++)
	{
		h3+=temp.back();
		temp.pop_back();
		stack3.push_back(h3);
	}
	if(stack1.size()<= stack2.size() && stack1.size() <= stack2.size())
		smallest=1;
	else if(stack2.size()<= stack1.size() && stack2.size() <= stack3.size())
		smallest=2;
	else if(stack3.size()<= stack1.size() && stack3.size() <= stack2.size())
		smallest=3;
	switch(smallest)
	{
		case 1:
            while(!stack1.empty())
				{
					if(find(stack2.begin(),stack2.end(),stack1.back())!=stack2.end() && find(stack3.begin(),stack3.end(),stack1.back())!=stack3.end())
					{
                        
						cout<<stack1.back();
						return 1;
					}
					stack1.pop_back();
				}
				printf("0");
				break;
		case 2: 
            while(!stack2.empty())
				{
                    
					if(find(stack1.begin(),stack1.end(),stack2.back())!=stack1.end() && find(stack3.begin(),stack3.end(),stack2.back())!=stack3.end())
					{
						cout<<stack2.back();
						return 1;
					}
					stack2.pop_back();
				}
				printf("0");
				break;
		case 3: 
            while(!stack3.empty())
				{
                    
					if(find(stack1.begin(),stack1.end(),stack3.back())!=stack1.end() && find(stack2.begin(),stack2.end(),stack3.back())!=stack2.end())
					{
						cout<<stack3.back();
						return 1;
					}
					stack3.pop_back();
				}
				printf("0");
				break;
	}

    return 0;
}