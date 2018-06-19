// https://github.com/keon/algorithms/blob/master/algorithms/dp/climbing_stairs.py

#include<iostream>
#include<vector>
using namespace std;

vector<int> dp(100000);
// The logic here is that the no. of steps at n is sum of steps at n-1 and n-2

// This uses memoization

int count(int n){
	if(n<=1)
		return n;
	int sum=0;
	if(dp[n-2]!=0)
		sum=dp[n-2];
	else{
		dp[n-2]=count(n-2);
		sum=dp[n-2];
	}
	if(dp[n-1]!=0)
		sum+=dp[n-1];
	else{
		dp[n-1]=count(n-1);
		sum+=dp[n-1];
	}
	return sum;
}

//This one doesn't
/*
int count(int n){
	if(n<=1)
		return n;
	return count(n-1)+count(n-2);
}
*/
int main(){
	int n;
	cin>>n;

	cout<<count(n+1)<<endl;

}
