// https://www.geeksforgeeks.org/dynamic-programming-set-17-palindrome-partitioning/

#include<bits/stdc++.h>

using namespace std;

int main(){
    string s="ababbbabbababa";
    int n=s.length();
    vector<vector<int>> count(n,vector<int>(n));
    vector<vector<bool>> P(n,vector<bool>(n,false));
    for(int i=0;i<n;i++)
        P[i][i]=true;
    
    for(int l=2;l<=n;l++){
        for(int i=0;i<n-l+1;i++){
            int j=i+l-1;
            
            if(l==2) P[i][j]=(s[i]==s[j]);
            else P[i][j]=(s[i]==s[j] && P[i+1][j-1]);
            
            if(P[i][j]) count[i][j]=0;
            else{
                count[i][j]=INT_MAX;
                for(int k=i;k<j;k++){
                    count[i][j]=min(count[i][k]+1+count[k+1][j],count[i][j]);
                }
            }
        }
    }
    
    cout<<count[0][n-1];
}