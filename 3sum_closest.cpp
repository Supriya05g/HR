// https://leetcode.com/problems/3sum-closest/description/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff=INT_MAX,cur_dif;
        int left,right,cur,act_dif;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            cur_dif=target-nums[i];
            left=i+1;
            right=nums.size()-1;
            while(left<right){
                if(abs(cur_dif-nums[left]-nums[right])<diff){
                    diff=abs(cur_dif-nums[left]-nums[right]);
                    act_dif=cur_dif-nums[left]-nums[right];
                    // cout<<nums[i]<<" "<<nums[left]<<" "<<nums[right]<<" "<<act_dif<<endl;
                }
                if(cur_dif-nums[left]-nums[right]<0)
                    right--;
                else if(cur_dif-nums[left]-nums[right]>0)
                    left++;
                else
                    return target;
            }
        }
        return target-act_dif;
    }
};