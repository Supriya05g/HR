// https://github.com/keon/algorithms/blob/master/algorithms/dp/max_product_subarray.py

#include<iostream>

using namespace std;

int max_product_subarray(int a[],int n){
	int max_ending_here=1;
	int min_ending_here=1;
	int max_so_far=1;

	for(int i=0;i<n;i++){
		if(a[i]>0){
			max_ending_here=max_ending_here*a[i];
			min_ending_here=min(min_ending_here*a[i],1);
		}
		else if(a[i]==0){
			max_ending_here=1;
			min_ending_here=1;
		}
		else{
		    int temp=max_ending_here;
			max_ending_here=max(min_ending_here*a[i],1);
			min_ending_here=temp*a[i];
		}

		if(max_so_far<max_ending_here)
			max_so_far=max_ending_here;
	}

	return max_so_far;
}

int main(){
	int n;
	cin>>n;
	int a[n];
	int i=0;
	while(cin>>a[i])
		i++;
	cout<<max_product_subarray(a,n)<<endl;
}