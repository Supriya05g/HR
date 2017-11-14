//https://www.hackerrank.com/challenges/apple-and-orange

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned long int s,t,a,b,m,n,i,j,count=0,x,y;
    cin>>s>>t>>a>>b>>m>>n;
    unsigned long int da[m],db[n];
    for(i=0;i<m;i++)
        cin>>da[i];
    for(i=0;i<n;i++)
        cin>>db[i];
    x=s-a;
    y=b-t;
    for(i=0;i<m;i++)
    {
        if( da[i]>=x && da[i]<=(x+t-s))
            count+=1;
    }
    cout<<count<<endl;
    count=0;
    for(i=0;i<n;i++)
    {
        if((-db[i])>=y && (-db[i])<=(y+t-s))
            count+=1;
    }
    cout<<count;
    return 0;
}