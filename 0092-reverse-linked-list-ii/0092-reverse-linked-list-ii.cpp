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
    ListNode* reverse(ListNode* head, int len){
        ListNode* curr=head;
        ListNode* prev=nullptr; ListNode* futur=nullptr;

        ListNode* temp=head;
        int count=0;
        while(count<len){
            temp=temp->next;
            count++;
        }
        
        while(len--){
            futur=curr->next;
            curr->next=prev;
            prev=curr;
            curr=futur;
        }
        head->next=temp;

        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* curr=dummy;
        ListNode* prev=NULL;
        int l=left;
        while(l-- ){
            prev=curr;
            curr=curr->next;
        }

        if(prev)
            prev->next=reverse(curr, right-left+1);
        
        return dummy->next;
    }
};