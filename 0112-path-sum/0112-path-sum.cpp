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
    //T.C->O(N) AND S.C->O(H) recursion stack
    bool hasPath(TreeNode* root, int &targetSum, int sum){
        if(root==NULL)  return false;
        if(root->left==NULL && root->right==NULL){
            return sum+(root->val)==targetSum;
        }
        // if(root->left==NULL && root->right==NULL && sum+(root->val)!=targetSum){
        //     return false;
        // }
        return hasPath(root->left, targetSum, sum+root->val) || hasPath(root->right, targetSum, sum+root->val);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        return hasPath(root, targetSum, 0);

    }
};