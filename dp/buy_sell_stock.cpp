// https://github.com/keon/algorithms/blob/master/algorithms/dp/buy_sell_stock.py

#include<bits/stdc++.h>

using namespace std;

int main(){
	long long n,max_sum,min_ele;
	cin>>n;
	vector<long long> a(n);
	
	for(long long i=0;i<n;i++)
		cin>>a[i];

	min_ele=a[0];
	max_sum=0;
	for(long long i=1;i<n;i++){
		if(a[i]-min_ele>max_sum)
			max_sum=a[i]-min_ele;
		else if(a[i]<min_ele)
			min_ele=a[i];
	}
	cout<<max_sum<<endl;
	return 0;
}
