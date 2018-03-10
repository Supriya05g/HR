// https://www.hackerrank.com/challenges/s10-geometric-distribution-2/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int factorial(int x){
    int prod=1;
    for(int i=2;i<=x;i++)
        prod*=i;
    return prod;
}

int ncr(int n,int r){
    return factorial(n)/(factorial(r)*factorial(n-r));
}

float power(float x,int n){
    float prod=x;
    if(n==0)
        return 1;
    for(int i=2;i<=n;i++)
        prod*=x;
    return prod;
}


int main() {
    int a,b,n;
    float res=1,prob;
    cin>>a>>b;
    prob=((float) a)/b;
    cin>>n;
    for(int i=0;i<n;i++){
        res*=(1-prob);
    }
    res=(1-res);
    cout<<setprecision(3)<<fixed<<res;
    return 0;
}
