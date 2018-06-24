// https://github.com/keon/algorithms/blob/master/algorithms/dp/min_cost_path.py

#include<iostream>
#include<algorithm>
#include<limits.h>
#include<string.h>

using namespace std;

int min_cost_path(int **a,int n,int m){
	int *dp=new int[m];
    // memset(dp,100000,n);
    for(int i=0;i<m;i++)
        dp[i]=INT_MAX;
    dp[0]=0;
    for(int i=0;i<n;i++)
    	for(int j=i+1;j<m;j++)
    		dp[j]=min(dp[j],dp[i]+a[i][j]);
	return dp[m-1]; 
}

int main(){
	int n,m;
	cin>>n>>m;

	int **a;
	a=new int*[n];

	for(int i=0;i<n;i++){
	    a[i]=new int[m];
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	}

	cout<<min_cost_path(a,n,m)<<endl;
}