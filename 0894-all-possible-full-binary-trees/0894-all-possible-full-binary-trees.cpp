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
    unordered_map<int, vector<TreeNode*>> mp;
    vector<TreeNode*> solve(int n){
        if(n==1)    return {new TreeNode(0)};
        if(mp.count(n)) return mp[n];

        vector<TreeNode*> res;
        for(int i=1; i<n; i+=2){
            auto L=solve(i);
            auto R=solve(n-i-1);
            for(auto &l: L){
                for(auto &r: R){
                    TreeNode* root=new TreeNode(0);
                    root->left=l;
                    root->right=r;
                    res.push_back(root);
                }
            }
        }
        return mp[n]=res;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n&1==0)  return {};
        return solve(n);
    }
};