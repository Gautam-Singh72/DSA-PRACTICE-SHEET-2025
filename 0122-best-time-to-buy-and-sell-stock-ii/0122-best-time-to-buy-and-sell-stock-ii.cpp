class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int i, bool canBuy, vector<int>& prices){
        if(i==n){
            return 0;
        }

        if(dp[i][canBuy] != -1)   return dp[i][canBuy];

        if(canBuy){
            return dp[i][canBuy]=max(-1*prices[i]+solve(i+1, 0, prices), solve(i+1, 1, prices));
        }
        
        return dp[i][canBuy]=max(prices[i]+solve(i+1, 1, prices), solve(i+1, 0, prices));
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        dp.assign(n, vector<int>(2, -1));
        
        return solve(0, 1, prices);
    }
};