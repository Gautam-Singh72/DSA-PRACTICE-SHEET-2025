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
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n=dungeon.size();
        m=dungeon[0].size();
        dp.resize(n, vector<int>(m, -1));
        return solve(0, 0, dungeon);
    }
};