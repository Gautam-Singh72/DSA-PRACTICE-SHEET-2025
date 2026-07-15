class Solution {
public:
    int m;
    int n;
    int MOD = 1e9+7;
    vector<vector<int>> dp; //auxilary space O(m*n)

    //T.C->O(m*n) each cell is visited atmost once
    //S.C->O(m*n) Aux space and O(m*n) rescursion stack space in worst case
    int dx[4]={-1, 0, 1, 0}; int dy[4]={0, -1, 0, 1};
    bool isValid(int r, int c){ //O(1)
        if(r<0 || r>=m || c<0 || c>=n){
            return false;
        }
        return true;
    }
    int solve(int i, int j, vector<vector<int>>& grid){

        if(dp[i][j] != -1)  return dp[i][j];

        int count=1;
        for(int k=0; k<4; k++){
            int r=i+dx[k];
            int c=j+dy[k];
            if(isValid(r, c) && grid[r][c]>grid[i][j]){
                count= (0LL + count + solve(r, c, grid)) % MOD;
            }
        }

        return dp[i][j]=count; //memoize the result to reduce overlapping sub problems
    }
    int countPaths(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        dp.resize(m, vector<int>(n, -1));

        int totalPath=0;
        for(int i=0; i<m; i++){ //O(m*n)
            for(int j=0; j<n; j++){
                totalPath=(0LL + totalPath + solve(i, j, grid)) % MOD;
            }
        }

        return totalPath;
    }
};