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
    unordered_map<string, vector<TreeNode*>> mp;
    vector<TreeNode*> solve(int start, int end){
        if(start>end)    return {NULL};
        if(start==end)    return {new TreeNode(start)};

        string key=to_string(start)+" "+to_string(end);
        if(mp.count(key))   return mp[key];

        vector<TreeNode*> res;
        for(int i=start; i<=end; i++){
            vector<TreeNode*> L=solve(start, i-1);
            vector<TreeNode*> R=solve(i+1, end);

            for(auto &l: L){
                for(auto &r: R){
                    TreeNode* root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    res.push_back(root);
                }
            }
        }
        return mp[key]=res;
    }
    vector<TreeNode*> generateTrees(int n) {
        
        return solve(1, n);
    }
};