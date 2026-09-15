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
    map<pair<TreeNode*, pair<int, int>>, int> mp;
    int dp(TreeNode* root, int rob, int par){
        if(!root)   return 0;
        if(!root->left && !root->right){
            if(rob) return root->val;
            return 0;
        }
        if(mp.count({root, {rob, par}}))    return mp[{root, {rob, par}}];

        if(rob){
            return root->val + dp(root->left, 0, 1) + dp(root->right, 0, 1);
        }
        return mp[{root, {rob, par}}] = max(dp(root->left, 0, 0), dp(root->left, 1, 0))+max(dp(root->right, 0, 0), dp(root->right, 1, 0));
    }
    int rob(TreeNode* root) {
        return max(dp(root, 0, 0), dp(root, 1, 0));
    }
};