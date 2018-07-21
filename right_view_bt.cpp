// https://leetcode.com/problems/binary-tree-right-side-view/description/

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> list;
        
        getlist(root,list,1);
        return list;
    }
    
    void getlist(TreeNode *root, vector<int>&list, int level){
        if(root==NULL)
            return;
        if(list.size()<level) 
            list.push_back(root->val);
        
        getlist(root->right,list,level+1);
        getlist(root->left,list,level+1);
    }
};