class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int prev=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            prev+=nums[i]*i;
        }

        int res=prev;
        for(int k=0; k<n; k++){
            int next=prev + sum - (n*(nums[n-1-k]));
            res=max(res, next);
            prev=next;
        }
        return res;
    }
};