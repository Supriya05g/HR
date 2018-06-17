// https://www.hackerrank.com/challenges/sherlock-and-cost/problem

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
	int dp[100000][2]={};
	int a[100000],n,t;

	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n-1;i++){
			dp[i+1][0]=max(dp[i][0],dp[i][1]+a[i]-1);
			dp[i+1][1]=max(dp[i][0]+a[i+1]-1,dp[i][1]+abs(a[i+1]-a[i]));
		}
		cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
	}

	return 0;
}

		
	
		

