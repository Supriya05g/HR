// https://www.hackerrank.com/challenges/s10-the-central-limit-theorem-3/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
	float mean,n_mean,std,n_std,n,z,prob,a,b;
	cin>>n>>mean>>std>>prob>>z;
	
	n_mean=mean/n;
	n_std=std/sqrt(n);
	
	a=mean-z*n_std;
	b=mean+z*n_std;

	cout<<setprecision(2)<<fixed<<a<<endl<<b;
    return 0;
}