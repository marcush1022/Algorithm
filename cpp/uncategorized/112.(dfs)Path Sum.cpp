/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding 
up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

class Solution {
public:
    bool dfs(TreeNode *root, int target)
    {
        if(root==NULL)
            return false;
        if(target==root->val && !root->left && !root->right)
            return true;
        return dfs(root->left, target-root->val) || dfs(root->right, target-root->val);
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root, sum);
    }
};


class Solution {
public:
    bool dfs(TreeNode *root, int sum, int tmp)
    {
        if(root==NULL)
            return false;
        if(tmp==sum-root->val && !root->left && !root->right)
            return true;
        return dfs(root->left, sum, tmp+root->val) || dfs(root->right, sum, tmp+root->val);
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root, sum, 0);
    }
};
