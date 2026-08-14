class Solution {
public:
    const int MOD=1e9+7;
    vector<vector<vector<int>>> dp;
    int solve(int n, int prev, int m, int k){
        if(n==0)    return k==0;
        if(k<0) return 0;
        if(dp[n][prev][k] != -1)    return dp[n][prev][k];
        
        long long count=0;
        for(int i=1; i<=m; i++){
            
            if(i>prev){
                count=(count + solve(n-1, i, m, k-1)) % MOD;
            }else{
                count=(count + solve(n-1, prev, m, k))%MOD;
            }
            
        }
        return dp[n][prev][k]=count;
    }
    int numOfArrays(int n, int m, int k) {
        dp.resize(n+1, vector<vector<int>>(m+1, vector<int>(k+1, -1)));

        return solve(n, 0, m, k);
    }
};