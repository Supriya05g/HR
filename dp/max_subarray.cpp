// https://www.hackerrank.com/challenges/maxsubarray/problem

#include<bits/stdc++.h>

using namespace std;

long long max_subarray(vector<int>&a,vector<long long>&dp,int n){
	long long max_sum=a[0],sum;	
		
	dp[0]=a[0];
	
	for(int i=1;i<n;i++){
		sum=dp[i-1]+a[i];
		if(sum>a[i]){
			if(sum<dp[i-1]){
				if(sum<0)
					dp[i]=a[i];
				else
					dp[i]=sum;
				max_sum=max(max_sum,dp[i-1]);
			}
			else
				dp[i]=sum;
		}
		else{	
			dp[i]=a[i];
			max_sum=max(max_sum,(long long) a[i]);

		}
	}
	return max(max_sum,dp[n-1]);
}

long long max_subseq(vector<int>&a,int n){
	long long max=-100005;
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	max=a[0];
	for(int i=1;i<n;i++){
		if(max<max+a[i])
			max=max+a[i];
	}
	return max;
}


int main(){

	int n,t;
	cin>>t;

	
	while(t--){	
		long long sum,max_seq;
		cin>>n;
		vector<int> a(n);
		vector<long long> dp(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		sum=max_subarray(a,dp,n);
		max_seq=max_subseq(a,n);
		cout<<sum<<"\t"<<max_seq<<endl;
	}
	return 0;
}
