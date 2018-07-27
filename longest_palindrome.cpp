// https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/

#include<bits/stdc++.h>

using namespace std;

string longest_palindrome(string s){
    int n=s.length();
    vector<vector<bool>> dp(n,vector<bool>(n,false));
    for(int i=0;i<n;i++)
        dp[i][i]=true;
    
    int maxlength=0,start=0;
    
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            dp[i][i+1]=true;
            start=i;
            maxlength=2;
        }
    }
    
    for(int k=3;k<=n;k++){
        for(int i=0;i<n-k+1;i++){
            int j=i+k-1;
            if(dp[i+1][j-1] && s[i]==s[j]){
                dp[i][j]=true;
                if(k>maxlength){
                    start=i;
                    maxlength=k;
                }
            }
        }        
    }
    
    return s.substr(start,maxlength);    
}

int main(){
    cout<<longest_palindrome("aaaabbbbxxxxx");
    return 0;
}