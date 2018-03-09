// https://www.hackerrank.com/challenges/s10-binomial-distribution-1/problem

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
	float a,b,res=0,p,q;
    int min,total;
	cin>>a>>b;
	p=a/(a+b);
	q=b/(a+b);
	min=3;
	total=6;
	for(int i=min;i<=total;i++){
		res+=ncr(total,i)*power(p,i)*power(q,total-i);
	}
	cout<<setprecision(3)<<fixed<<res;
    return 0;
}
