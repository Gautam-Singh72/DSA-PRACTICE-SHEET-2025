class Solution {
public:
    // int solve(int i, int j, string &s1, string &s2, vector<vector<int>>& dp){
    //     if(i==0 || j==0){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1)    return dp[i][j];

    //     if(s1[i-1]==s2[j-1])    return dp[i][j]=1+solve(i-1, j-1, s1, s2, dp);
    //     int left=solve(i-1, j, s1, s2, dp);
    //     int right=solve(i, j-1, s1, s2, dp);
    //     return dp[i][j]=max(left, right);
    // }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(), t.end());
        int n=s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        //Base Case 
        for(int j=0; j<=n; j++)     dp[0][j]=0;
        for(int i=0; i<=n; i++)      dp[i][0]=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    continue;
                } 
                int left=dp[i-1][j];
                int right=dp[i][j-1];
                dp[i][j]=max(left, right);
            }
        }
        return dp[n][n];
    }
};