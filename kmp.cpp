// https://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/

#include<bits/stdc++.h>

using namespace std;

vector<int> build_lps(string s){
	vector<int> lps(s.length());
	int index=0;
	for(int i=1;i<s.length();){
		if(s[i]==s[index]){
			lps[i++]=++index;
		}
		else{
			if(index!=0) index=lps[index-1];
			else i++;
		}

	}
	return lps;
}

int match_pattern(string text,string pat){
	vector<int> lps=build_lps(pat);
	int i=0,j=0;
	int m=text.length();
	int n=pat.length();
	while(i<m && j<n){
		if(text[i]==pat[j]){
			i++;
			j++;
		}
		else{
			if(j!=0) j=lps[j-1];
			else i++;
		}
	}
	if(j==n)
		return i-j;
	return -1;
}

int main(){
	cout<<match_pattern("aacdaacdaaacdaac","aacdaac");
	return 0;
}