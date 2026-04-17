class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, int n, int m, string &s, string &t){
        if(j>=m)  return 1;
        if(i>=n)  return 0;
        if(dp[i][j]!=-1)    return dp[i][j];

        int take=0;
        if(s[i]==t[j]){
            take=solve(i+1, j+1, n, m, s, t);
        }
        int skip=solve(i+1, j, n, m, s, t);
        
        return dp[i][j]=take+skip;
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        dp.resize(n, vector<int>(m, -1));
        return solve(0, 0, n, m, s, t);
    }
};