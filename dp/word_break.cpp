// https://github.com/keon/algorithms/blob/master/algorithms/dp/word_break.py

#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

bool word_break(string s,vector<string> &dict){
    int n=s.length();
	bool dp[n+1];
	for(int i=0;i<=n;i++){
		dp[i]=false;
		cout<<dp[i]<<endl;
	}

	dp[0]=true;
/*
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			
			string cur=s.substr(j,i-j);
			bool present=false;
			for(int k=0;k<dict.size();k++)
			    if(cur==dict[k]){
			        present=true;
			        break;
			    }
			    
			if(dp[j] && present){
				dp[i]=true;
				break;
			}
		}
	}*/

	return dp[n];
}

int main(){
	int n;
	cin>>n;

	vector<string> dict(n);

	for(int i=0;i<n;i++)
		// getline(cin,dict[i]);
		cin>>dict[i];

	string str;
	// getline(cin,str);
	cin>>str;

	cout<<word_break(str,dict);
	return 0;
}