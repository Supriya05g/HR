// https://leetcode.com/problems/sum-of-subarray-minimums/description/

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n=A.size();
        vector<int> left(n),right(n);
        stack<pair<int,int>> sl,sr;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            int count=1;
            while(!sl.empty() && sl.top().first >= A[i]){
                count+=sl.top().second;
                sl.pop();
            }
            sl.push({A[i],count});
            left[i]=count;
        }
        for(int i=n-1;i>=0;i--){
            int count=1;
            while(!sr.empty() && sr.top().first > A[i]){
                count+=sr.top().second;
                sr.pop();
            }
            sr.push({A[i],count});
            right[i]=count;
        }
        int res=0;
        for(int i=0;i<n;i++){
            res=(res+A[i]*left[i]*right[i])%mod;
        }
        return res;
    }
};