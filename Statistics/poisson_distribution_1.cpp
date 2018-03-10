// https://www.hackerrank.com/challenges/s10-poisson-distribution-1/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

#define E 2.718
using namespace std;

int factorial(int n){
	int prod=1;
	for(int i=2;i<=n;i++)
		prod*=i;
	return prod;
}

float e_power(float x){
	return pow(E,x);
}

int main() {
	float lambda,k,res;
	cin>>lambda>>k;
	res=pow(lambda,k)*e_power(-lambda)/factorial(k);
	cout<<setprecision(3)<<fixed<<res;
    return 0;
}
