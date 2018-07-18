// https://leetcode.com/problems/balanced-binary-tree/description/

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
    int check(TreeNode *root,int height,bool &res){
        if(root==NULL)
            return height;
        
        height++;
        int lh,rh;
        lh=check(root->left,height,res);
        rh=check(root->right,height,res);
        if(abs(lh-rh)>1)
            res=false;
        return max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        bool res=true;
        int height=1;
        check(root,height,res);
        
        return res;
    }
};