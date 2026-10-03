/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int solve(ListNode* head){
        int count=0;
        ListNode* temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=solve(headA);
        int len2=solve(headB);

        if(len2>len1){
            swap(headA, headB);
            swap(len2, len1);
        }

        int diff=len1-len2;
        while(diff>0 && headA){
            headA=headA->next;
            diff--;
        }

        while(headA && headB){
            if(headA==headB)    return headA;

            headA=headA->next;
            headB=headB->next;
        }

        return nullptr;
    }
};