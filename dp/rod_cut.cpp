// https://github.com/keon/algorithms/blob/master/algorithms/dp/rod_cut.py

#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

int rod_cut(int price[],int n){
	// int *dp=new int[n];
	vector<int> dp(n+1);

	for(int i=1;i<=n;i++){
		int max_val=INT_MIN;
		for(int j=0;j<i;j++){
			max_val=max(max_val,price[j]+dp[i-j-1]);
		}
		dp[i]=max_val;
	}

	return dp[n];
}

int main(){
	int n;
	cin>>n;
	int a[n];
	int i=0;
	while(cin>>a[i])
		i++;
	cout<<rod_cut(a,n)<<endl;
}