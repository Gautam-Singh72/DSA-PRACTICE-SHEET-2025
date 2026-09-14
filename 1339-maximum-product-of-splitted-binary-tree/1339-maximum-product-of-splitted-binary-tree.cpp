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
    typedef long long ll;
    ll totalSum;
    ll res;
    int MOD=1e9+7;
    

    ll findSum(TreeNode* root){
        if(!root)   return 0;

        return root->val+solve(root->left)+solve(root->right);
    }
    ll solve(TreeNode* root){
        if(!root)   return 0;


        ll leftSum=solve(root->left);

        ll splitedTreeSum=totalSum-leftSum;
        res=max(res, leftSum * splitedTreeSum);

        ll rightSum=solve(root->right);
        splitedTreeSum=totalSum-rightSum;
        res=max(res,  rightSum * splitedTreeSum);

        return root->val+leftSum+rightSum;

    }
    int maxProduct(TreeNode* root) {
        totalSum=findSum(root);
        res=0;

        solve(root);
        return res % MOD;
    }
};