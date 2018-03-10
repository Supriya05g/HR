// https://www.hackerrank.com/challenges/s10-normal-distribution-2/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;


int main() {
	float mean,std,x,inp1,res;
	cin>>mean>>std;

	//Probabilty where the person scored more than 80%
	cin>>inp1;
    // cout<<erf(-0.5/2)<<endl;
	res=0.5*(1+erf((inp1-mean)/(std*sqrt(2))));
	cout<<setprecision(2)<<fixed<<100*(1.0-res)<<endl;

	
	//Probabilty where the person scored more than 60%(passed) 
	cin>>inp1;
	res=0.5*(1+erf((inp1-mean)/(std*sqrt(2))));
	cout<<setprecision(2)<<fixed<<100*(1.0-res)<<endl;
	
	//Probabilty where the person scored less than 60%(failed) 
	cout<<setprecision(2)<<fixed<<100*res<<endl;

    return 0;
}
