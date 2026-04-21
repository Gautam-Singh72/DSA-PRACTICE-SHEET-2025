class Solution {
public:
    int m, n;
    int dx[4]={-1, 0, 1, 0}; int dy[4]={0, -1, 0, 1};
    int solve(int i, int j, vector<vector<int>>& grid){
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j]=0;
        int size=0;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            size++;
            int r=p.first;
            int c=p.second;
            for(int k=0; k<4; k++){
                int nr=r+dx[k];
                int nc=c+dy[k];
                if(nr<0 || nr>=m || nc<0 || nc>=n)  continue;
                if(grid[nr][nc]==1){
                    q.push({nr, nc});
                    grid[nr][nc]=0;
                }
            }
        }
        return size;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int res=INT_MIN;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    res=max(res, solve(i, j, grid)) ;
                }
            }
        }
        return res==INT_MIN ? 0 : res;
    }
};