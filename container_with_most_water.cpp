// https://leetcode.com/problems/container-with-most-water/description/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int h,water=0,i=0,j=height.size()-1;
        while(i<j){
            h=min(height[j],height[i]);
            water=max(water,(j-i)*h);
            while(i<j && height[i]<=h) i++;
            while(i<j && height[j]<=h) j--;
            
        }
        return water;
    }
};