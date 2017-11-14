//https://www.hackerrank.com/challenges/grading/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        if(a[i]<38)
            cout<<a[i]<<endl;
        else 
        {
            m=((a[i]/5)+1)*5;
            if(m-a[i]<3)
                cout<<m<<endl;
            else
                cout<<a[i]<<endl;
        }
    return 0;
}
