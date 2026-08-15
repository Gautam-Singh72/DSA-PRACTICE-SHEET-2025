/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum=INT_MIN;
    int solve(TreeNode* root){
        if(!root)   return 0;
        // if(!root->left && !root->right) return root->val;
  
        int left=solve(root->left);
        int right=solve(root->right);
        
        int res=root->val;
        res=max(res, root->val+left+right);
        res=max(res, root->val+left);
        res=max(res, root->val+right);
        maxSum=max(maxSum, res);
        
        return max({root->val, root->val+left, root->val+right});
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};