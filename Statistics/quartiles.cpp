// https://www.hackerrank.com/challenges/s10-quartiles/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int n,i,median1,median2,median3,ele;
	cin>>n;
	vector<int> arr;
	for(i=0;i<n;i++){
		cin>>ele;
		arr.push_back(ele);
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
			median1=(arr[n/4]+arr[n/4-1])/2;
			median3=(arr[n/2+n/4]+arr[n/2+n/4+1])/2;
		}

	}
	else {
		median2=(arr[n/2-1]+arr[n/2+1])/2;
		if((n/2)%2==1) {
			median1=arr[n/4];
			median3=arr[n/4+n/2+1];
		}
		else {
			median1=(arr[n/4]+arr[n/4-1]);
			median3=(arr[n/2+n/4]+arr[n/2+n/4-1])/2;
		}

	}
	cout<<median1<<endl;
	cout<<median2<<endl;
	cout<<median3<<endl;
    return 0;
}
