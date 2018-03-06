// https://www.hackerrank.com/challenges/s10-standard-deviation/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
	int n,ele,i;
	float sum=0,mean=0,std;
	vector<int>arr;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>ele;
		mean+=ele;
		arr.push_back(ele);
	}
	mean=mean/n;
	for(i=0;i<n;i++)
	{
		sum+=(mean-arr[i])*(mean-arr[i]);
	}
	std=sqrt(sum/n);
	cout<<setprecision(1)<<fixed<<std;
    return 0;
}
