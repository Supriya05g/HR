// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int n,lcount=0,hcount=0;
	unsigned long int ele,highest=0,lowest=0;
	cin>>n;
	cin>>ele;
	highest=lowest=ele;
	for(int i=0;i<n-1;i++)
	{
		cin>>ele;
		if(ele>highest)
		{
			highest=ele;
			hcount++;
		}
		else if(ele<lowest)
		{
			lowest=ele;
			lcount++;
		}
	}
	cout<<hcount<<" "<<lcount;
    return 0;
}
