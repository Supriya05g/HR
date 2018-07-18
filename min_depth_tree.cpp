// https://leetcode.com/problems/minimum-depth-of-binary-tree/description/

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
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int lh=minDepth(root->left);
        int rh=minDepth(root->right);
        if(lh==0 || rh==0)
            return lh+rh+1;
        else
            return min(lh,rh)+1;
    }
};