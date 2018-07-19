// https://leetcode.com/problems/path-sum/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return false;
        sum=sum-root->val;
        if(root->left==NULL && root->right==NULL && sum==0)
            return true;
        bool res=hasPathSum(root->left,sum);
        if(res)
            return true;
        res=hasPathSum(root->right,sum);
        return res;
    }
};