class Solution {
public:
    const int M=1e9+7;
    int dx[4]={-1, 0, 1, 0}; int dy[4]={0, -1, 0, 1};
    int solve(int i, int j, int move, int m, int n, vector<vector<vector<int>>>& dp){
        if(i<0 || i>=m || j<0 || j>=n)  return 1;
        if(move<=0) return 0;
        if(dp[i][j][move] != -1)    return dp[i][j][move];

        int count=0;
        for(int k=0; k<4; k++){
            int r=i+dx[k];
            int c=j+dy[k];
            count=(count+solve(r, c, move-1, m, n, dp))%M;
        }

        return dp[i][j][move]=count;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return solve(startRow, startColumn,  maxMove, m, n, dp);
    }
};