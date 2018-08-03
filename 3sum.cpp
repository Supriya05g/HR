// https://leetcode.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int target=0;
        vector<vector<int>>results;
        for(int i=0;i<n-2 && nums[i]<=0;i++){
            target=nums[i];
            int k=n-1;
            int j=i+1;
            while(j<k){
                if(nums[j]+nums[k]+target==0){
                    vector<int> res;
                    res.push_back(target);
                    res.push_back(nums[j]);
                    res.push_back(nums[k]);
                    if(find(results.begin(),results.end(),res)==results.end())
                        results.push_back(res);
                    while (j < k && nums[i] == res[1]) j++;    
                    while (j < k && nums[k] == res[2]) k--;    
                }
                
                if(nums[j]+nums[k]>(-target)) k--;
                else j++;
            }
        }
        return results;
    }
};