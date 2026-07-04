class Solution {
public:
    int m;
    int n;
    vector<vector<bool>> visited;
    int dx[4]={-1, 0, 1, 0}; int dy[4]={0, -1, 0, 1};
    bool isValid(int r, int c){
        if(r<0 || r>=m || c<0 || c>=n)  return false;

        return true;
    }
    // int dfs(int i, int j, vector<vector<int>>& grid){
    //     if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0) return 1;

    //     grid[i][j]=0;
    //     int count=0;
    //     for(int k=0; k<4; k++){
    //         int r=i+dx[k]; int c=j+dy[k];
    //         count+=dfs(r, c, grid)
    //     }
    //     return count;
    // }
    int bfs(int i, int j, vector<vector<int>>& grid){
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j]=true;

        int res=0;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int r=p.first;
            int c=p.second;
            int count=0;
            for(int k=0; k<4; k++){
                int next_r=r+dx[k]; int next_c=c+dy[k];
                if(isValid(next_r, next_c) && grid[next_r][next_c]==1 && !visited[next_r][next_c]){
                    q.push({next_r, next_c});
                    visited[next_r][next_c]=true;
                }else{
                    if(isValid(next_r, next_c) && grid[next_r][next_c] == 1 && visited[next_r][next_c]) continue;
                    
                    count++;
                }
            }
            res+=count;
        }
        return res;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        visited.resize(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    return bfs(i, j, grid);
                }
            }
        }
        return -1;
    }
};