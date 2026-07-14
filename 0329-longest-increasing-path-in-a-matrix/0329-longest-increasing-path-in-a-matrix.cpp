class Solution {
public:
    int m;
    int n;
    vector<vector<int>> dp;

    int dx[4]={-1, 0, 1, 0}; int dy[4]={0, -1, 0, 1};

    bool isValid(int r, int c){
        return r>=0 && r<m && c>=0 && c<n;
    }
    int solve(int i, int j, vector<vector<int>>& matrix){


        if(dp[i][j] != -1)  return dp[i][j];

        int maxlen=1;
        for(int k=0; k<4; k++){
            int r=i+dx[k];
            int c=j+dy[k];
            
            if(isValid(r, c)  && matrix[r][c]>matrix[i][j]){
                maxlen=max(maxlen, 1+solve(r, c, matrix));
            }
        }

        
        return dp[i][j]=maxlen;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        dp.resize(m, vector<int>(n, -1));
        int res=-1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                res=max(res, solve(i, j, matrix));
            }
        }

        return res;
    }
};