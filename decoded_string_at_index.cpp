// https://leetcode.com/contest/weekly-contest-96/problems/decoded-string-at-index/

class Solution {
public:
    string decodeAtIndex(string s, int K) {
        long N=0,i;
        // First get count of total number of letters until N>K
        for(i=0;N<K;i++)
            N= isdigit(s[i])? N*(s[i]-'0'):N+1;
        //Now once N>K, we traverse backwards. If the current element is a digit, then divide N with that number and set K with remainder of K/N. 
        // If the character is a letter, check if N%K==0 and if it is true, return that character. Else reduce N by 1.
        while(i--){
            if(isdigit(s[i])){
                N/=(s[i]-'0');
                K%=N;
            }
            else{
                if(K%N==0)
                    return string(1,s[i]);
                N--;
            }
        }
    }
};