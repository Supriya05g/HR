// https://leetcode.com/problems/path-sum-ii/description/


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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        vector<int>path;
        get_paths(root,sum,paths,path);
        return paths;
    }
    
    void get_paths(TreeNode *root,int sum,vector<vector<int>>&paths,vector<int> &path){
        if(root==NULL)
            return;
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL && sum-root->val==0)
            paths.push_back(path);
        get_paths(root->left,sum-root->val,paths,path);
        get_paths(root->right,sum-root->val,paths,path);
        path.pop_back();
    }
};

