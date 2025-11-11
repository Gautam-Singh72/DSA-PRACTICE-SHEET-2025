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
         //T.C->O(N) AND S.C->O(1) USING MORRIS TRAVERSAL
    void recoverTree(TreeNode* root) {
        TreeNode* curr=NULL, *prev=NULL;
        TreeNode* first=NULL, *second=NULL;

        while(root!=NULL){
            //if left does not exist
            if(root->left==NULL){
                prev=curr;
                curr=root;
                if(prev && curr->val<prev->val){
                    if(first==NULL){
                        first=prev;
                    }
                    second=curr;
                }
                
                root=root->right;
            }
            // if left exist
            else{
                TreeNode* temp=root->left;
                while(temp->right && temp->right!=root){
                    temp=temp->right;
                }
                if(temp->right==NULL){
                    temp->right=root;
                    root=root->left;
                }else{
                    temp->right=NULL;
                    prev=curr;
                    curr=root;
                    if(prev && curr->val<prev->val){
                        if(!first){
                            first=prev;
                        }
                        second=curr;
                    }
                    root=root->right;
                }
            }
        }
        int x=first->val;
        first->val=second->val;
        second->val=x;
    }
};