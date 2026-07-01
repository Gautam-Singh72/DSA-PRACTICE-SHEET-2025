class Solution {
public:
    bool isValid(int r, int c, int n){
        return r>=0 && r<n && c>=0 && c<n;
    }
    int dx[4]={-1, 0, 1, 0}; int dy[4]={0, -1, 0, 1};
    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& grid){
        int n=grid.size();
        while(!q.empty()){
            pair<int, int> p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            for(int k=0; k<4; k++){
                int r=i+dx[k]; int c=j+dy[k];
                if(isValid(r, c, n) && grid[r][c]==0){
                    if(grid[i][j]==-1){
                        grid[r][c]=1;
                    }else{
                        grid[r][c]=grid[i][j]+1;
                    }
                    q.push({r, c});
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==-1){
                    grid[i][j]=0;
                }
            }
        }
    }
    bool isPossible(vector<vector<int>> grid, int safeFactor){
        int n=grid.size();
        queue<pair<int, int>> q;
        if(grid[0][0]>=safeFactor){
            q.push({0, 0});
            grid[0][0]=-1;  
        }

        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            if(i==n-1 && j==n-1)    return true;
            for(int k=0; k<4; k++){
                int r=i+dx[k]; int c=j+dy[k];
                if(isValid(r, c, n) && grid[r][c]>=safeFactor){
                    if(r==n-1 && j==n-1)    return true;
                    q.push({r, c});
                    grid[r][c]=-1;
                }
            }
        }
        return false;
    }
    int solve(vector<vector<int>>& grid){
        int n=grid.size();
        int start=0;
        int end=n;
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;

            if(isPossible(grid, mid)){
                ans=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        // if(n==1)    return 0;
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    q.push({i, j});
                    grid[i][j]=-1;
                }
            }
        }
        bfs(q, grid);

        return solve(grid);
    }
};