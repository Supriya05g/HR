// https://www.hackerrank.com/challenges/s10-the-central-limit-theorem-2/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
	float x,n,mean,std,n_mean,n_std,res;
	cin>>x>>n>>mean>>std;

	n_mean=mean*n;
	n_std=std*n;

	res=0.5*(1+erf((x-n_mean)/(n_std*sqrt(2))));
	
	cout<<setprecision(4)<<fixed<<res;
    return 0;
}