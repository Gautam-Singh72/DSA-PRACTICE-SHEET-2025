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
    unordered_map<long long, int> mp;
    int solve(TreeNode* root, long long sum, int target){
        if(!root)   return 0;

        sum+=root->val;
        int count=0;
        if(mp.count(sum-target)) count+=mp[sum-target];
        mp[sum]++;

        int left=solve(root->left, sum, target);
        int right=solve(root->right, sum, target);

        mp[sum]--;

        return left+right+count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0]=1;
        return solve(root, 0, targetSum);
    }
};