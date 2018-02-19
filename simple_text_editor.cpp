// https://www.hackerrank.com/challenges/simple-text-editor/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() 
{
	string str,inp,del_str,add_str,prev_str;
    stack<int> input_stack;
    stack<string> str_stack;
	int input,prev;
	long int n,k,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>input;
		switch(input)
		{
			case 1: cin>>inp;
					str.append(inp);
					add_str=inp;
                    str_stack.push(add_str);
                    input_stack.push(1);
					break;
			case 2: cin>>k;
					del_str=str.substr(str.length()-k);
					str.erase(str.length()-k,k);
                    input_stack.push(2);
                    str_stack.push(del_str);
					break;
			case 3: cin>>k;
					cout<<str.at(k-1)<<"\n";
					break;
			case 4: prev=input_stack.top();
                    input_stack.pop();
                    prev_str=str_stack.top();
                    str_stack.pop();
                    if(prev==1)
						str.erase(str.length()-prev_str.length(),prev_str.length());
					else if(prev==2)
						str.append(prev_str);
					break;
		}
	}
    return 0;
}
