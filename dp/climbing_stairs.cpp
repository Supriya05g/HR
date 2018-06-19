// https://github.com/keon/algorithms/blob/master/algorithms/dp/climbing_stairs.py

#include<iostream>

using namespace std;

int main(){
	int n,a=1,b=1,c;
	cin>>n;
	
	for(int i=0;i<n;i++){
		c=a;
		a=b;
		b=c+b;
	}

	cout<<a<<endl;
}
