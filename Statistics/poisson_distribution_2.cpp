// https://www.hackerrank.com/challenges/s10-poisson-distribution-2/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

// #define E 2.718
using namespace std;

int main() {
	float lambda1,lambda2,k,res,expectation1,expectation2,cost1,cost2;
	cin>>lambda1>>lambda2;

	expectation1=lambda1*lambda1+lambda1;
	expectation2=lambda2*lambda2+lambda2;
	
	cost1=160+40*expectation1;
	cost2=128+40*expectation2;

	cout<<setprecision(3)<<fixed<<cost1<<endl<<cost2;
    return 0;
}
