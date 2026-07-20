class Solution {
public:
   vector<int> dp;
    //T.C-O(n*n) and S.C->O(n)
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n, 1);

        int res=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i], 1+dp[j]);
                }
            }
            res=max(res, dp[i]);
        }
        return res;
    }
};