class Solution {
public:
    const int NEG_INF=-1e9;
    int dx[4]={-1, 0, 1, 0}; int dy[4]={0, -1, 0, 1};
    bool isValid(int i, int j, int n){
        if(i<0 || i>=n || j<0 || j>=n)  return false;
        return true;
    }
    int bfs(int i, int j, int id, vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j]=id;
        int size=0;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            size++;
            for(int k=0; k<4; k++){
                int r=p.first+dx[k];
                int c=p.second+dy[k];
                if(isValid(r, c, n) && grid[r][c]==1){
                    q.push({r, c});
                    grid[r][c]=id;
                }
            }
        }
        return size;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int, int> mp;
        int id=2;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    int size=bfs(i, j, id, grid);
                    mp[id]=size;
                    id++;
                }
            }
        }
        unordered_set<int> s;
        int maxSize=NEG_INF;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    s.clear();
                    for(int k=0; k<4; k++){
                        int r=i+dx[k];
                        int c=j+dy[k];
                        if(isValid(r, c, n) && grid[r][c]!=0){
                            s.insert(grid[r][c]);
                        }
                    }
                    int size=0;
                    for(auto num: s){
                        size+=mp[num];
                    }
                    maxSize=max(maxSize, size+1);
                }
            }
        }

        return maxSize==NEG_INF ? n*n : maxSize;
    }
};