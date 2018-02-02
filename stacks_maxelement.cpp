// https://www.hackerrank.com/challenges/maximum-element/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	unsigned int n,type;
	unsigned long int ele;
	stack<unsigned long int> st,max;
	// max.push(0);
    cin>>n;
    cin>>type>>ele;
    if(type==1)
    {
        st.push(ele);
        max.push(ele);
    }
	for(unsigned int i=0;i<n-1;i++)
	{
		cin>>type;
		if(type==1)
		{
			cin>>ele;
			st.push(ele);
			if(max.size()==0 || ele>=max.top())
				max.push(ele);
		}
		if(type==2)
        {
            if(max.top()==st.top())
                max.pop();
            st.pop();
            
        }
			
		if(type==3)
			cout<<max.top()<<"\n";
	}	

    return 0;
}