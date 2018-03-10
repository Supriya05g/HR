// https://www.hackerrank.com/challenges/s10-geometric-distribution-1/problem	

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    int a,b,n;
    float res=1,prob;
    cin>>a>>b;
    prob=((float) a)/b;
    cin>>n;
    for(int i=1;i<n;i++){
    	res*=prob;
    }
    res*=1-prob;
    cout<<setprecision(3)<<fixed<<res;
    return 0;
}
