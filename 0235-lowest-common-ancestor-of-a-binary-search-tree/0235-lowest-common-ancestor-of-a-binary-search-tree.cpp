/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public://T,C->O(N)  IN WORST CASE AND S.C->O(H)-(N) IN WORST CASE 
        //LEFT OR RIGHT SKEWD BST
    TreeNode* lcaBst(TreeNode* root, TreeNode* p, TreeNode* q){
        // if(root==NULL)  return NULL;
        if(p->val<root->val && q->val<root->val){
            return lcaBst(root->left, p, q);
        }
        if(p->val>root->val && q->val>root->val){
            return lcaBst(root->right, p, q);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lcaBst(root, p, q);
    }
};