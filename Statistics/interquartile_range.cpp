// https://www.hackerrank.com/challenges/s10-interquartile-range/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;


int main() {
	int n,i,median1,ele;
	float median2,median3;
	cin>>n;
	vector<int> arr;
	queue<int> temp;
	for(i=0;i<n;i++){
		cin>>ele;
		temp.push(ele);
	}
	for(i=0;i<n;i++){
		cin>>ele;
		for(int j=0;j<ele;j++){
			arr.push_back(temp.front());
			temp.pop();
		}
	}

	sort(arr.begin(),arr.end());
	if(n%2==1)
	{
		median2=arr[n/2];
		if((n/2)%2==1){
			median1=arr[n/4];
			median3=arr[n/4+n/2+1];
		}
		else {
			median1=(arr[n/4]+arr[n/4-1])/2.0;
			median3=(arr[n/2+n/4]+arr[n/2+n/4+1])/2.0;
		}

	}
	else {
		median2=(arr[n/2-1]+arr[n/2+1])/2;
		if((n/2)%2==1) {
			median1=arr[n/4];
			median3=arr[n/4+n/2+1];
		}
		else {
			median1=(arr[n/4]+arr[n/4-1])/2.0;
			median3=(arr[n/2+n/4]+arr[n/2+n/4-1])/2.0;
		}

	}
	cout<<setprecision(1)<<median3-median1;
    return 0;
}
