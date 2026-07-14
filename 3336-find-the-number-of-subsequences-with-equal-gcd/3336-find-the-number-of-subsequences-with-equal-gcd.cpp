class Solution {
public:
    int MOD=1e9+7;
    int dp[201][201][201];
    int solve(int i, int first, int second, vector<int>& nums){
        if(i==nums.size()){
            bool bothNonEmpty=(first && second);
            bool gcdEqual=(first==second);

            return bothNonEmpty && gcdEqual;
        }

        if(dp[i][first][second] != -1)  return dp[i][first][second];

        int skip=solve(i+1, first, second, nums);

        int take1=solve(i+1, __gcd(first, nums[i]), second, nums);

        int take2=solve(i+1, first, __gcd(second, nums[i]), nums);

        return dp[i][first][second]=(0LL + skip + take1 + take2)%MOD;
    }
    int subsequencePairCount(vector<int>& nums) {
        
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0, nums);
    }
};