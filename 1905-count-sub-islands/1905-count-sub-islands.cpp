class Solution {
public:
    int m;
    int n;
    bool isValid(int r, int c){
        if(r<0 || r>=m || c<0 || c>=n)  return false;
        return true;
    }
    int dx[4]={-1, 0, 1, 0}; int dy[4]={0, -1, 0, 1};
    bool bfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        queue<pair<int, int>> q;
        q.push({i, j});
        // grid1[i][j]=0; we dont have to chnage grid1
        grid2[i][j]=0;
        bool flag=true;
        while(!q.empty()){
            pair<int, int> p=q.front();
            q.pop();
            int row=p.first;
            int col=p.second;
            for(int k=0; k<4; k++){
                int nextRow=row+dx[k];
                int nextCol=col+dy[k];
                if(isValid(nextRow, nextCol) && grid2[nextRow][nextCol]==1){
                    if(grid1[nextRow][nextCol]==0)  flag=false;
                    q.push({nextRow, nextCol});
                    grid2[nextRow][nextCol]=0;
                }
            }
        }
        return flag;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m=grid1.size();
        n=grid1[0].size();

        int count=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid1[i][j]==1 && grid2[i][j]==1 && bfs(i, j, grid1, grid2)){
                    count++;
                }
            }
        }
        return count;
    }
};