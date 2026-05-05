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
    void solve(vector<int>& arr, int k){
        int n=arr.size();
        reverse(arr.begin(), arr.begin()+n-k);
        reverse(arr.begin()+n-k, arr.end());
        reverse(arr.begin(), arr.end());
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0)  return head;
        vector<int> arr;
        ListNode* temp=head;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int len=arr.size();
        k=k%len;
        solve(arr, k);
        temp=head;
        for(int i=0; i<len; i++){
            temp->val=arr[i];
            temp=temp->next;
        }
        return head;
    }
};