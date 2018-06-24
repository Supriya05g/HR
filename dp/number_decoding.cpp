// https://github.com/keon/algorithms/blob/master/algorithms/dp/num_decodings.py

#include<iostream>
#include<string.h>

using namespace std;

int count(string str,int n){
	int dp[n];
    if(str[0]-'0'==0)
        return 0;
	dp[0]=1;
	for(int i=1;i<n;i++){
		int num=10*(str[i-1]-'0')+(str[i]-'0');
		int sum=dp[i-1];
		if(i==1 && num<26){
		    if(str[i]-'0'==0)
		        dp[i]=1;
	        else
    			dp[i]=2;
			continue;
		}
		else if(str[i]-'0'==0){
		    if(str[i-1]-'0'==1 || str[i-1]-'0'==2)
    			dp[i]=dp[i-2];
    		else
    		    return 0;
			continue;
		}
		else if(str[i-1]-'0'==0){
			dp[i]=dp[i-1];
			continue;
		}
		else if(num<26){
			sum+=dp[i-2];
		}
		dp[i]=sum;
	}

	return dp[n-1];

}

int main(){
	int n;
	string num;
	getline(cin,num);
// 	cout<<num.length();
	cout<<count(num,num.length())<<endl;

	return 0;
}