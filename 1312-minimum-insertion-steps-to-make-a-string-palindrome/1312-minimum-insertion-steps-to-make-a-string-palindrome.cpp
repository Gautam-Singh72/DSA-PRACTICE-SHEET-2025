class Solution {
public:
    vector<vector<int>> dp;
    int minInsertions(string s) {
        int n=s.size();
        string t=s;
        reverse(t.begin(), t.end());
        dp.resize(n+1, vector<int>(n+1, -1));

        for(int i=0; i<=n; i++){
            dp[i][0]=0;
        }
        for(int j=0; j<=n; j++){
            dp[0][j]=0;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1]; continue;
                }

                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }

        int len=dp[n][n];
        int ans=(n-len);

        return ans;
    }
};