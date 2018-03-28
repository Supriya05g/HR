// https://www.hackerrank.com/contests/rookierank-4/challenges/exam-rush

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
// #include <stdlib>
using namespace std;


int main() {
    
    int n,t,i;
    cin>>n>>t;
    vector<int> ct(n);
    for(int i=0;i<n;i++)
        cin>>ct[i];
    sort(ct.begin(),ct.end());
    int sum=0;
    // if(t<ct[0])
        
    for(i=0;i<n;i++){
        if(sum+ct[i]>t){
            cout<<i;
            exit(0);
        }
        else if(sum+ct[i]==t){
            cout<<i+1;
            exit(0);
        }
        else
            sum+=ct[i];
    }
    cout<<i+1;    
    return 0;
}
