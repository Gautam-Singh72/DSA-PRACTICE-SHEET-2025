class Solution {
public:
    int m;
    int n;
    vector<vector<bool>> visited;
    vector<vector<vector<int>>> dp;
    int dx[4]={-1, 0, 1, 0}; int dy[4]={0, -1, 0, 1};
    bool isValid(int i, int j){
        if(i<0 || i>=m || j<0 || j>=n)  return false;

        return true;
    }
    bool solve(int i, int j, int health, vector<vector<int>>& grid){
        if(health<=0)  return false;
        if(dp[i][j][health] != -1)  return dp[i][j][health];

        int h=(grid[i][j]==1) ? health-1 : health;
        if(i==m-1 && j==n-1 && h>0)   return true;

        visited[i][j]=true;
        for(int k=0; k<4; k++){
            int new_i=i+dx[k];
            int new_j=j+dy[k];
            if(isValid(new_i, new_j) && !visited[new_i][new_j]){
                if(solve(new_i, new_j, h, grid)){
                    return true;
                }
            }
        }
        visited[i][j]=false;
        return dp[i][j][health]=false;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m=grid.size();
        n=grid[0].size();
        visited.resize(m, vector<bool>(n, false));
        dp.resize(m, vector<vector<int>>(n, vector<int>(health+1, -1)));
        return solve(0, 0, health, grid);
    }
};