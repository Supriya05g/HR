// https://www.geeksforgeeks.org/meet-in-the-middle/

#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

void subarray(vector<ll> &sub,vector<ll>&arr,int c){

	for(int i=0;i<sub.size();i++){
		ll s=0;
		for(int j=0;j<arr.size();j++){
			if(i &(1<<j))
			s+=arr[j+c];
		}
		sub[i]=s;
	}
}

int get_sum(vector<ll> &arr,int num){
	int n=arr.size();
	vector<ll> X(1<<(n/2));
	vector<ll> Y(1<<(n-n/2));

	subarray(X,arr,0);
	subarray(Y,arr,n/2);

	sort(Y.begin(),Y.end());
    ll max=0;
    
	for(int i=0;i<X.size();i++){
		if(X[i]<=num){
			int p=lower_bound(Y.begin(),Y.end(),num-X[i])-Y.begin();

			if(p==Y.size() || Y[p]!=(num-X[i]))
				p--;

			if(max<Y[p]+X[i])
				max=Y[p]+X[i];
		}
	}
	return max;
}

int main(){
	vector<ll> arr{3, 34, 4, 12, 5, 2};
	ll S = 42;
	printf("Largest value smaller than or equal to given "
	       "sum is %lld\n", get_sum(arr,S));
	return 0;
	
}