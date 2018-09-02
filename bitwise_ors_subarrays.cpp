// https://leetcode.com/contest/weekly-contest-100/problems/bitwise-ors-of-subarrays/

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        
        unordered_set<int> ans,cur,temp;
        
        for(auto i:A){
            temp={i};
            for(auto j:cur)
                temp.insert(i|j);
            cur=temp;
            for(auto j:cur)
                ans.insert(j);
        }
        
        return ans.size();
        
    }
};