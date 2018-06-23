// https://github.com/keon/algorithms/blob/master/algorithms/dp/longest_increasing.py

#include<iostream>
#include <algorithm>
#include<string.h>

using namespace std;

int lis(int a[],int n){
	int *dp = new int[n];
// 	memset(dp,1,n);
    
    for(int i=0;i<n;i++)
        dp[i]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i]>a[j])
				dp[i]=max(dp[i],dp[j]+1);
		}
// 		cout<<dp[i]<<" ";
	}
	int res=*max_element(dp,dp+n);
	delete[] dp;
	
	return res;
	
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

	cout<<lis(a,n)<<endl;
	return 0;
}