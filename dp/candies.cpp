// https://www.hackerrank.com/challenges/candies/problem

#include<bits/stdc++.h>

using namespace std;

int main(){
	// vector<long long> values(1000000);
	// vector<int>rating;
	int rating[100000+5];
	long long values[100000+5];
	long long sum,temp;
	int i,n;

	cin>>n;
	for(i=0;i<n;i++)
		cin>>rating[i];

	values[0]=1;
	for(i=1;i<n;i++){
		if(rating[i]>rating[i-1])
			values[i]=values[i-1]+1;
		else
			values[i]=1;
	}

	sum=values[n-1];
	cout<<values[n-1]<<" ";
	for(i=n-2;i>=0;i--){
		if(rating[i]>rating[i+1])
			temp=values[i+1]+1;
		else
			temp=1;
		values[i]=max(temp,values[i]);
		sum+=values[i];
		cout<<values[i]<<" ";
	}

	cout<<endl<<sum<<endl;

	return 1;

}