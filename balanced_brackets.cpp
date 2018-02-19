// https://www.hackerrank.com/challenges/balanced-brackets/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string.h>
using namespace std;


int main() {
	int n,flag=0;
    cin>>n;
	for(int i=0;i<n;i++)
	{
        flag=0;
		string inp;
		stack<char>brackets;
		cin>>inp;
		for(int j=0;j<inp.length();j++)
		{
            if(brackets.empty() && (inp[j]==']' || inp[j]==')' || inp[j]=='}') )
            {
                cout<<"NO\n";
                flag=1;
                break;
            }
			if(inp.at(j)=='[' || inp[j]=='(' || inp[j]=='{' )
				brackets.push(inp[j]);
			else if((inp.at(j)==']' && brackets.top()!='[') || (inp.at(j)==')' && brackets.top()!='(') || (inp.at(j)=='}' && brackets.top()!='{'))
				{
					cout<<"NO\n";
					flag=1;
					break;
				}
			else
				brackets.pop();
		}
		if(brackets.empty() && flag!=1)
			cout<<"YES\n";
	}
    return 0;
}
