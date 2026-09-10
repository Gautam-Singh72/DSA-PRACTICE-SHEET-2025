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
    int count=0;
    pair<int, int> solve(TreeNode* root){
        if(!root)   return {0, 0};

        pair<int, int> p=solve(root->left);
        int leftNodeCount=p.first;
        int leftNodeSum=p.second;

        pair<int, int> q=solve(root->right);
        int rightNodeCount=q.first;
        int rightNodeSum=q.second;

        int sum=leftNodeSum + rightNodeSum + root->val;
        int n=leftNodeCount + rightNodeCount + 1;
        int avg=sum/n;
        cout<<avg<<" ";

        if(avg==root->val)  count++;
        

        return {n, sum};

    }
    int averageOfSubtree(TreeNode* root) {
        count=0;

        solve(root);

        return count;
    }
};