// https://www.hackerrank.com/contests/rookierank-4/challenges/winning-hand-of-cards/problem

//Couldn't solve this on my own.
//Editorial solution. Complexity: O(n*m)
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int a[35];
ll dp[2][1000005];
int main() {
	int n,m,x,state=0;
	scanf("%d",&n); scanf("%d",&m); scanf("%d",&x);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) {
		for(int j=0;j<m;j++) dp[state][j]=dp[state^1][j];
		for(int j=0;j<m;j++) dp[state][((ll)j*a[i])%m]+=dp[state^1][j];
		dp[state][a[i]%m]++;
		state^=1;
	}
	printf("%lld\n",dp[state^1][x]);
	return 0;
}

