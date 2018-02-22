// https://www.hackerrank.com/challenges/simple-array-sum/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int n,ele,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ele;
		sum+=ele;
	}
	cout<<sum;

    return 0;
}
