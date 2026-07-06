class Solution {
public:
    const int M=1e9+7;
    vector<vector<int>> dp;
    vector<vector<vector<int>>> t;
    int solve(int i, int j, vector<string>& board){
        if(i<0 || j<0 || board[i][j]=='X')  return INT_MIN;
        if(board[i][j]=='E'){
            return 0;
        }
        if(dp[i][j] != -1)  return dp[i][j];

        int val=(board[i][j]=='S') ? 0 : board[i][j]-'0';
        int left= val + solve(i-1, j, board);
        int up= val + solve(i, j-1, board);
        int diag= val + solve(i-1, j-1, board); 

        return dp[i][j]=max({left, up, diag});
    }
    int countPath(int i, int j, int target, vector<string>& board){
        if(i<0 || j<0 || board[i][j]=='X')  return 0;
        if(board[i][j]=='E'){
            return target==0;
        }
        if(t[i][j][target] != -1)   return t[i][j][target];

        int val=(board[i][j]=='S') ? 0 : board[i][j]-'0';
        int left= countPath(i-1, j, target-val, board);
        int up= countPath(i, j-1, target-val, board);
        int diag= countPath(i-1, j-1, target-val, board); 

        return t[i][j][target]=(left+up+diag)%M;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m=board.size();
        int n=board[0].size();
        dp.resize(n, vector<int>(n, -1));
        
        int maxSum=-1;
        maxSum=solve(m-1, n-1, board);
        if(maxSum<0)  return {0, 0};
        
        t.resize(n, vector<vector<int>>(n, vector<int>(maxSum+1, -1)));
        int count=countPath(n-1, n-1, maxSum, board);

        
        return {maxSum, count};
    }
};