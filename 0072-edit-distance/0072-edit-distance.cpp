class Solution {
public:
    int solve(int i, int j, string w1, string w2, vector<vector<int>>& dp){
        if(i<0 && j<0)  return 0;
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1)    return dp[i][j];

        if(w1[i]==w2[j])    return dp[i][j]=solve(i-1, j-1, w1, w2, dp);

        int insert=1+solve(i, j-1, w1, w2, dp);
        int del=1+solve(i-1, j, w1, w2, dp);
        int rep=1+solve(i-1, j-1, w1, w2, dp);

        return dp[i][j]=min({insert, del, rep});
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m-1, n-1, word1, word2, dp);
    }
};