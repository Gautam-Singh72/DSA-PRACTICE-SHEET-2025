class Solution {
public:
    int n;
    int m;
    vector<vector<int>> dp;
    int solve(int i, int j, vector<vector<int>>& dungeon){
        if(i==n-1 && j==m-1){
            if(dungeon[i][j]>0){
                return 1;
            }
            return 1+abs(dungeon[i][j]);
        }
        if(i>=n || j>=m)    return INT_MAX;
        if(dp[i][j]!=-1)    return dp[i][j];

        int right=solve(i, j+1, dungeon);
        int down=solve(i+1, j, dungeon);

        int res=min(right, down)-dungeon[i][j];
        return dp[i][j]=res<=0 ? 1 : res;
    }
    //T.C->O(N*M) AND S.C->O(N*M) AUXILARY SPACE RECURSION SPACE REDUCES IN TABULATION
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n=dungeon.size();
        m=dungeon[0].size();
        dp.resize(n+1, vector<int>(m+1));
        //base case 
        for(int i=0; i<=n; i++){
            dp[i][m]=INT_MAX;
        }
        for(int j=0; j<=m; j++){
            dp[n][j]=INT_MAX;
        }
        dp[n-1][m-1]=dungeon[n-1][m-1]>0 ? 1 : 1+abs(dungeon[n-1][m-1]);

        //recursive case 
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i==n-1 && j==m-1)    continue;
                int right=dp[i][j+1];
                int down=dp[i+1][j];

                int res=min(right, down)-dungeon[i][j];
                dp[i][j]=res<=0 ? 1 : res;
            }
        }
        return dp[0][0];
    }
};