class Solution {
public:  
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int count_zero=0;
        int temp=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0)  count_zero++;

            temp^=nums[i];
        }
        if(count_zero==n)   return 0;

        return temp==0 ? n-1 : n;
    }
};