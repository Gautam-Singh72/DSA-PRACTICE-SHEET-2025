class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int player, int n){
        if(n==0){
            return player==1;
        }

        if(dp[n][player] != -1) return dp[n][player];
        
        if(!player){
            for(int i=1; i*i<=n; i++){
                if(solve(player^1, n-i*i)){
                    return dp[n][player]=true;
                }
            }
            return dp[n][player]=false;
        }
        for(int i=1; i*i<=n; i++){
            if(solve(player^1, n-i*i)==false){
                return dp[n][player]=false;
            }
        }
        return dp[n][player]=true;
    }
    bool winnerSquareGame(int n) {
        int player=0;
        dp.resize(n+1, vector<int>(2, -1));
        return solve(0, n);
    }
};