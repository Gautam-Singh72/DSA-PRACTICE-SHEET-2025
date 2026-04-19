class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int i, int j, string s, string p){
        if(i==0 && j==0)    return true;
        if(i==0 && j>0){
            while(j>0){
                if(p[j-1]!='*')   return false;
                j--;
            }
            return true;
        }
        if(j==0 && i>0)   return false;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i-1]==p[j-1] || p[j-1]=='?')  return dp[i][j]=solve(i-1, j-1, s, p);
        if(p[j-1]=='*')   return dp[i][j]=solve(i-1, j, s, p) || solve(i, j-1, s, p);

        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        dp.resize(n+1, vector<int>(m+1, -1));

        dp[0][0]=true;
        for(int j=1; j<=m; j++){
            int idx=j;
            bool flag=true;
            while(idx>0){
                if(p[idx-1]!='*'){
                    dp[0][j]=false;
                    flag=false;
                    break;
                }
                idx--;
            }
            if(flag)    dp[0][j]=true;
        }
        for(int i=1; i<=n; i++){
            dp[i][0]=false;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?')   dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')   dp[i][j]=dp[i-1][j] || dp[i][j-1];

                else dp[i][j]=false;
            }
        }


        return dp[n][m];
    }
};