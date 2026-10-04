class Solution {
public:
    int n;
    vector<vector<int>> dp;
    bool solve(int i, int diff, string& s){
        if(i==n)    return diff==0;
        if(diff<0)  return false;
        if(dp[i][diff] != -1)   return dp[i][diff];

        if(s[i]=='*'){
            return dp[i][diff]=solve(i+1, diff+1, s) || solve(i+1, diff-1, s) || solve(i+1, diff, s);
        }

        if(s[i]=='('){
            return dp[i][diff]=solve(i+1, diff+1, s);
        }

        return dp[i][diff]=solve(i+1, diff-1, s);
    }
    bool checkValidString(string s) {
        n=s.size();
        dp.resize(n, vector<int>(n+1, -1));

        return solve(0, 0, s);
    }
};