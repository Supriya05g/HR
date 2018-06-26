// https://github.com/keon/algorithms/blob/master/algorithms/dp/job_scheduling.py

#include<iostream>
#include<algorithm>

using namespace std;

typedef struct Job{
	int start,finish,profit;
}Job;

bool job_compare(Job j1,Job j2){
	return (j1.finish<j2.finish);
}

int latest_nonconflict(Job a[],int n){
	for(int i=n-1;i>=0;i--)
		if(a[i-1].finish<=a[n].start)
			return i;
	return -1;
}

int max_profit(Job a[],int n){

	sort(a,a+n,job_compare);

	int *table= new int[n];
	for(int i=0;i<n;i++)
		table[i]=-1;
	table[0]=a[0].profit;

	for(int i=1;i<n;i++){
		
		int incl=a[i].profit;
		int l=latest_nonconflict(a,i);
		if(l!=-1)
			incl+=table[l];

		table[i]=max(incl,table[i-1]);

	}

	int result=table[n-1];
	delete[] table;

	return result;
}

int main(){

	int n;
	cin>>n;
	Job a[n];
	for(int i=0;i<n;i++){
		cin>>a[i].start>>a[i].finish>>a[i].profit;
	}

	cout<<max_profit(a,n);

	return 0;
}

