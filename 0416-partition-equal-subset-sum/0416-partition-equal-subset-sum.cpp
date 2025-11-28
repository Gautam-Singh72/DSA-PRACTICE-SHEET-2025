class Solution {
public:
    //T.C->O(N*target) S.C->O(N*target) TABULATION
    bool solve(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target==0)   return true;
        if(i<0 || target<0) return false;
        if(dp[i][target]!=-1)    return dp[i][target];

        return dp[i][target]=(solve(i-1, target, nums, dp) || solve(i-1, target-nums[i], nums, dp));
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto &num: nums){
            sum+=num;
        }
        if(sum%2!=0)    return false;
        int n=nums.size();
        int target=sum/2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        for(int i=0; i<n; i++){
            dp[i][0]=true;
        }
        for(int i=0; i<n; i++){
            for(int j=1; j<target+1; j++){
                if(i-1>=0 && j-nums[i]>=0)
                dp[i][j]=(dp[i-1][j] || dp[i-1][j-nums[i]]);
                else{
                    if(i>0){
                        dp[i][j]=dp[i-1][j];
                    }else{
                    dp[i][j]=false;
                    }
                }
            }
        }
        return dp[n-1][target];
    }
};