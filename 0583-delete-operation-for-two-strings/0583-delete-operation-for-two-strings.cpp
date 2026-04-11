class Solution {
public:
    // int solve(int i, int j, string word1, string word2, vector<vector<int>>& dp){
    //     if(i==0 && j==0)  return 0;
    //     if(i==0) return j; -j is actually j+1
    //     if(j==0) return i;

    //     if(dp[i][j]!=-1)    return dp[i][j];
    //     // if(j<0 && i>=0) return i+1;
    //     // if(i<0 && j>=0) return j+1;
    //     // if(i<0 && j<0)  return 0;

    //     if(word1[i-1]==word2[j-1])  return dp[i][j]=solve(i-1, j-1, word1, word2, dp);

    //     int l=1+solve(i-1, j, word1, word2, dp);
    //     int r=1+solve(i, j-1, word1, word2, dp);

    //     return dp[i][j]=min(l, r);
    // }
    int minDistance(string word1, string word2) {
        int m=word1.size(); 
        int n=word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        //Tabulation 
        //stop the rcursion to go <0 to easly filled dp table
        for(int j=0; j<n+1; j++){
            dp[0][j]=j;
        }
        for(int i=0; i<m+1; i++){
            dp[i][0]=i;
        }
        dp[0][0]=0;
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                    continue;
                }
                dp[i][j]=1+min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};