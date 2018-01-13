// https://www.hackerrank.com/challenges/sparse-arrays/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,q,i,count,j;
    string test;
    cin>>n;
    vector<string> s(n);
    for(i=0;i<n;i++)
        cin>>s[i];
    cin>>q;
    
    for(i=0;i<q;i++)
    {
        cin>>test;
        count=0;
        for(j=0;j<n;j++)
        {
            if(s[j]==test)
                count++;
        }
        cout<<count<<"\n";
    }
    return 0;
}