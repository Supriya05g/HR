// https://www.hackerrank.com/contests/rookierank-4/challenges/server-room-safety

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<pair<int,int>>position(n);
    for(int i=0;i<n;i++)
        cin>>position[i].first;
    int i;
    for(i=0;i<n;i++){
        cin>>position[i].second;
    }
    
    sort(position.begin(),position.end());
    string result="NONE";
    int flag1=0,flag2=0;
    int flags[n]={0};
    for(i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
        if(position[i].first+position[i].second>=position[j].first)
            flags[j-1]=1;
        else
            break;
        }
    }
    for(i=0;i<n-1;i++)
        if(flags[i]==0){
            flag1=1;
            break;
        }
    if(flag1==0)
        result="LEFT";
    fill_n(flags,n,0);
    for(i=n-1;i>0;i--){
        for(int j=i-1;j>=0;j--){
        if( position[i].first-position[i].second<=position[j].first)
            flags[j+1]=1;
        else 
            break;
        }
    }
    for(i=1;i<n;i++)
        if(flags[i]==0){
            flag2=1;
            break;
        }
    if(flag2==0)
        result="RIGHT";
    if(flag1==0 && flag2==0)
        result="BOTH";
    cout<<result;    
    return 1;
}

