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
    map<pair<TreeNode*, int>, int> mp;
    int solve(TreeNode* root, int rob){
        if(!root)   return 0;
        if(mp.count({root, rob}))   return mp[{root, rob}];
        
        if(rob){
            return mp[{root, rob}]=root->val + solve(root->left, 0) + solve(root->right, 0);
        }
        return mp[{root, rob}] = max(solve(root->left, 1), solve(root->left, 0))+max(solve(root->right, 1), solve(root->right, 0));
    }
    int rob(TreeNode* root) {
        return max(solve(root, 1), solve(root, 0));
    }
};