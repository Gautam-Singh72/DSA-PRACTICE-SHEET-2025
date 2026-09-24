class Solution {
public:
    int n;
    vector<vector<int>> dp;
    // int solve(int i, bool canBuy, vector<int>& prices){
    //     if(i==n){
    //         return 0;
    //     }

    //     if(dp[i][canBuy] != -1)   return dp[i][canBuy];

    //     if(canBuy){
    //         return dp[i][canBuy]=max(-1*prices[i]+solve(i+1, 0, prices), solve(i+1, 1, prices));
    //     }
        
    //     return dp[i][canBuy]=max(prices[i]+solve(i+1, 1, prices), solve(i+1, 0, prices));
    // }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        dp.assign(n+1, vector<int>(2, -1));

        dp[n][0]=dp[n][1]=0;
        for(int i=n-1; i>=0; i--){
            for(int canBuy=0; canBuy<=1; canBuy++){
                if(canBuy){
                    dp[i][canBuy]=max(-1*prices[i]+dp[i+1][0],  dp[i+1][1]);
                }else{
                    dp[i][canBuy]=max(prices[i]+dp[i+1][1],  dp[i+1][0]);
                }
            }
        }

         return dp[0][1];
    }
};