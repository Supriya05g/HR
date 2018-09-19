// https://leetcode.com/explore/interview/card/top-interview-questions-medium/109/backtracking/795/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms;
        vector<int> cur;
        vector<bool> chosen(nums.size(),false);
        compute(nums, cur, perms, chosen);
        return perms;
        
    }
    void compute(vector<int> & nums, vector<int> &cur, vector<vector<int>> &perms,vector<bool> &chosen ){
        if(cur.size()==nums.size()){
            perms.push_back(cur);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(chosen[i]) continue;
            chosen[i]=true;
            cur.push_back(nums[i]);
            compute(nums, cur, perms, chosen);
            cur.pop_back();
            chosen[i]=false;
        }
    }
    
};