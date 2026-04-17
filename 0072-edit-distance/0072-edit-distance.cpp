class Solution {
public:
    
    int minDistance(string w1, string w2) {
        int m=w1.size();
        int n=w2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        dp[0][0]=0;
        for(int j=0; j<=n; j++){
            dp[0][j]=j;
        }
        for(int i=0; i<=m; i++){
            dp[i][0]=i;
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(i==0 && j==0)    continue;
                if(w1[i-1]==w2[j-1])    dp[i][j]=dp[i-1][j-1];
                else{
                    int insert=1+dp[i][j-1];
                    int del=1+dp[i-1][j];
                    int rep=1+dp[i-1][j-1];

                    dp[i][j]=min({insert, del, rep});
                }
            }
        }

        return dp[m][n];
    }
};