/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* insert(TreeNode* root, int val){
        if(root==NULL){
            TreeNode* temp=new TreeNode(val);
            return temp;
        }
        if(val<root->val)
        root->left=insert(root->left, val);
        else
        root->right=insert(root->right, val);

        return root;
    }
    void listToBST(ListNode* head, TreeNode* &root){
        if(head==NULL){
            return;
        }
        ListNode* slow=head;
        ListNode* fast=head; ListNode* prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        root=insert(root, slow->val);
        if(head->next==NULL)    return;
        ListNode* temp=slow->next;
        if(prev!=NULL)
            prev->next=NULL;
        listToBST(head, root);
        listToBST(temp, root);
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        TreeNode* root=NULL;
        listToBST(head, root);
        return root;
    }
};