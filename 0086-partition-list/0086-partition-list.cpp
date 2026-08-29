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
class Solution {
public:
    ListNode* solve(ListNode* head, int x){
        ListNode* h1=new ListNode(-1);
        ListNode* h2=new ListNode(-1);
        ListNode* temp=head;
        ListNode* t1=h1;
        ListNode* t2=h2;

        while(temp){
            if(temp->val < x){
                t1->next=temp;
                t1=t1->next;
            }else{
                t2->next=temp;
                t2=temp;
            }
            temp=temp->next;
        }
        t1->next=h2->next;
        t2->next=nullptr;
        return h1->next;
    }
    ListNode* partition(ListNode* head, int x) {
        if(!head)   return head;
        
        return solve(head, x);
    }
};