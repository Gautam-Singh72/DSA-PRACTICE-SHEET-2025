class Solution {
public:
    int m, n;
    // bool solve(int i, int j, int left, int right, vector<vector<char>>& grid){
    //     if(i>=m || j>=n )    return false;
    //     if(right>left)  return false;
    //     if(i==m-1 && j==n-1){
    //         if(grid[i][j]=='(') left++;
    //         else right++;
    //         return left == right;
    //     }

    //     if(grid[i][j]=='('){
    //         return solve(i, j+1, left+1, right, grid) || solve(i+1, j, left+1, right, grid);
    //     }

    //     return solve(i, j+1, left, right+1, grid) || solve(i+1, j, left, right+1, grid);
    // }

    vector<vector<vector<int>>> dp;
    bool solve(int i, int j, int diff, vector<vector<char>>& grid){
        if(i>=m || j>=n || diff<0)  return false;
        if(i==m-1 && j==n-1){
            diff+=grid[i][j]=='(' ? 1 : -1;
            return diff==0;
        }

        if(dp[i][j][diff] != -1)    return dp[i][j][diff];

        if(grid[i][j]=='('){
            return dp[i][j][diff]=solve(i, j+1, diff+1, grid) || solve(i+1, j, diff+1, grid);
        }

        return dp[i][j][diff]=solve(i, j+1, diff-1, grid) || solve(i+1, j, diff-1, grid);

    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(201, -1)));
        return solve(0, 0, 0, grid);
    }
};