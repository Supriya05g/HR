// https://www.hackerrank.com/challenges/s10-weighted-mean/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    int n,i,sum_weights=0,ele;
    long int sum=0; 
    vector<int>arr;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        arr.push_back(ele);
    }
    for(i=0;i<n;i++)
    {
        cin>>ele;
        sum_weights+=ele;
        sum+=ele*arr[i];
    }
    cout<<setprecision(1)<<fixed<<float(sum)/sum_weights;
    
    return 0;
}
