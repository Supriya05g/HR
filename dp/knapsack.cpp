// https://github.com/keon/algorithms/blob/master/algorithms/dp/knapsack.py

#include<iostream>
#include<algorithm>

using namespace std;

typedef struct Knapsack{
	int weight,value;
}knapsack;

int max_value(knapsack a[],int n,int W){
	int dp[n+1][W+1];

	for(int i=0;i<=n;i++){
		for(int w=0;w<=W;w++){
			if(w==0 || i==0)
				dp[i][w]=0;
			else if(a[i-1].weight<=w)
				dp[i][w]=max(a[i-1].value+dp[i-1][w-a[i-1].weight],dp[i-1][w]);
			else
				dp[i][w]=dp[i-1][w];
		}
	}

	//Print items
	int w=W;
	int res=dp[n][W];
	printf("Items in knapsack: \n");
	for(int i=n; i>0 && res>0;i--){
		if(dp[i-1][w]==dp[i][w])
			continue;
		else{
			printf("%d  ",a[i-1].weight);
		    res = res - val[i - 1];
			w=w-a[i-1].weight;
		}
	}

	return K[n][W];
		
}



/*
int get_last_best(knapsack a[],int n,int capacity){
	for(int i=n-1;i>=0;i--){
		if(a[n].weight+a[i].weight<=capacity)
			return i+n;
	}
	return -1;
}

bool compare(knapsack a,knapsack b){
	return (a.weight<b.weight);
}

int max_value(knapsack a[],int n,int capacity){

	sort(a,a+n,compare);

	int *dp=new int[n];
	memset(dp,0,n);
	dp[0]=a[0].value;

	for(int i=1;i<n;i++){
		if(a[i].weight<=capacity){
			int incl=a[i].value;
			int l=get_last_best(a,i,capacity);
			if(l!=-1)
				incl+=a[l].value;

			dp[i]=max(incl,dp[i-1]);
		}
		else
			return dp[i-1];

	}

	int result=dp[n-1];
	delete[] dp;

	return result;
}
*/
int main(){
	int n,capacity;
	cin>>n>>capacity;

	knapsack a[n];
	for(int i=0;i<n;i++)
		cin>>a[i].weight>>a[i].value;

	cout<<max_value(a,n,capacity);

	return 0;
}