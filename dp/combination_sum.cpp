// github.com/keon/algorithms/blob/master/algorithms/dp/combination_sum.py

#include<iostream>
#include<vector>
#include<ctime>
#include<sys/time.h>

using namespace std;

int bottom_up(vector<int> &num,int target){
	vector<int> dp(target+1);
	dp[0]=1;

	for(int i=0;i<target+1;i++)
		for(int j=0;j<num.size();j++)
			if(i>=num[j])
				dp[i]+=dp[i-num[j]];
	
	return dp[target];

}

int topdown(vector<int> &num,vector<int> &dp,int target){
	
	if(dp[target]!=-1)
		return dp[target];
	
	int res=0;
	for(int i=0;i<num.size();i++)
		if(target>=num[i])
			res+=topdown(num,dp,target-num[i]);
	
	dp[target]=res;

	return dp[target];
}

int main(){
	int n,target;
	
	time_t time1,time2;
	timeval tv2,tv1;

	cin>>n>>target;
	vector<int>num(n);
	for(int i=0;i<n;i++)
		cin>>num[i];
	
	vector<int>dp(target+1,-1);


	int res;
	dp[0]=1;
	
	// gettimeofday(&tv1, 0);
	res=topdown(num,dp,target);
	// gettimeofday(&tv2, 0);
	cout<<res<<endl;


	// gettimeofday(&tv1, 0);
	res=bottom_up(num,target);
	// gettimeofday(&tv1, 0);
	cout<<res<<endl;
	
	return 0;
}

