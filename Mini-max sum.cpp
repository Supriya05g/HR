// https://www.hackerrank.com/challenges/mini-max-sum/problem


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long int findsum(unsigned long int a[],int i,unsigned long int num,int j)
{
    if(i==4)
    {
        if(i!=j)
            return a[i];
        else 
            return 0;
    }
    if(i!=j)
        return a[i]+findsum(a,i+1,num,j);
    else
        return findsum(a,i+1,num,j);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned long int a[5],min=0,max=0,sum=0;
    for(int i=0;i<5;i++)
        cin>>a[i];
    min=max=findsum(a,0,a[0],0);
    //cout<<min<<" "<<max;
    for(int i=1;i<5;i++)
    {
        sum=findsum(a,0,a[i],i);
        if(sum<min)
            min=sum;
        else if(sum>max)
            max=sum;
    }
    cout<<min<<" "<<max;
    return 0;
}