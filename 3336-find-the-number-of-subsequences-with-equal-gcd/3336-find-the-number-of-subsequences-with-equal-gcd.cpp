class Solution {
public:
    int MOD=1e9+7;
    
    // int solve(int i, int first, int second, vector<int>& nums){
    //     if(i==nums.size()){
    //         bool bothNonEmpty=(first && second);
    //         bool gcdEqual=(first==second);

    //         return bothNonEmpty && gcdEqual;
    //     }

    //     if(dp[i][first][second] != -1)  return dp[i][first][second];

    //     int skip=solve(i+1, first, second, nums);

    //     int take1=solve(i+1, __gcd(first, nums[i]), second, nums);

    //     int take2=solve(i+1, first, __gcd(second, nums[i]), nums);

    //     return dp[i][first][second]=(0LL + skip + take1 + take2)%MOD;
    // }
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        int maxVal=*max_element(nums.begin(), nums.end());
        int dp[n+1][maxVal+1][maxVal+1];
        memset(dp, 0, sizeof(dp));

        
        //base case
        for(int first=0; first<=maxVal; first++){
            for(int second=0; second<=maxVal; second++){
                bool bothNonEmpty=(first && second);
                bool gcdEqual=(first==second);
                if(bothNonEmpty && gcdEqual){
                    dp[n][first][second]=1;
                }
            }
        }

        for(int i=n-1; i>=0; i--){
            for(int first=maxVal; first>=0; first--){
                for(int second=maxVal; second>=0; second--){
                    int skip=dp[i+1] [first] [second];

                    int take1=dp[i+1] [__gcd(first, nums[i])] [second];

                    int take2=dp[i+1] [first] [__gcd(second, nums[i])];

                    dp[i][first][second]=(0LL + skip + take1 + take2)%MOD;
                }
            }
        }
        return dp[0][0][0];
    }
};