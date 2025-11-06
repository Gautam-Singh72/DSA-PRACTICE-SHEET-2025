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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)    return ans;
        queue<int> q2;
        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            level.push_back(n);
            while(n){
                TreeNode* temp=q.front();
                q.pop();
                q2.push(temp->val);
                if(temp->left!=NULL)    q.push(temp->left);
                if(temp->right!=NULL)   q.push(temp->right);
                n--;
            }
        }
        for(int i=0; i<level.size(); i++){
            vector<int> temp;
            while(level[i]--){
                temp.push_back(q2.front());
                q2.pop();
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};