class Solution {
public:
    vector<vector<int>> dp;
    // int solve(int i, int prev, vector<int>& nums){
    //     if(i>=nums.size())  return 0;
    //     if(dp[i][prev+1]!=-1)   return dp[i][prev+1];

    //     int pick=INT_MIN;
    //     if(prev==-1 || nums[i]>nums[prev]){
    //         pick=1+solve(i+1, i, nums);
    //     }
    //     int notPick=solve(i+1, prev, nums);

    //     return dp[i][prev+1] = max(pick, notPick);
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n+1, vector<int>(n+1, -1));

        for(int prev=-1; prev<n; prev++){
            dp[n][prev+1]=0;
        }

        for(int i=n-1; i>=0; i--){
            for(int prev=i-1; prev>=-1; prev--){
                int pick=INT_MIN;
                if(prev==-1 || nums[i]>nums[prev]){
                    pick=1+dp[i+1] [i+1];
                }
                int notPick=dp[i+1] [prev+1];

                dp[i][prev+1] = max(pick, notPick);
            }
        }

        return dp[0][0];
    }
};