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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next == nullptr) return {-1, -1};
        int first=-1;
        int last=-1;
        int maxDis=INT_MIN;
        int minDis=INT_MAX;

        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* futur=curr->next;
        int i=2;
        while(futur){
            if(curr->val>prev->val && curr->val>futur->val){
                if(first==-1){
                    first=i;
                    last=i;
                }else{
                    maxDis=max(maxDis, i-first);
                    minDis=min(minDis, i-last);
                    last=i;
                }
            }else if(curr->val<prev->val && curr->val<futur->val){
                if(first==-1){
                    first=i;
                    last=i;
                }else{
                    minDis=min(minDis, i-last);
                    maxDis=max(maxDis, i-first);
                    last=i;
                }
            }
            prev=curr;
            curr=futur;
            futur=futur->next;
            i++;
        }

        if(maxDis==INT_MIN) return {-1, -1};

        return {minDis, maxDis};
    }
};