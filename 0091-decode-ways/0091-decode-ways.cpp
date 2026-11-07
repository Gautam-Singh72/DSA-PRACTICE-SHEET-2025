class Solution {
public:
    int n;
    vector<int> dp;
    int solve(int i, string &s){
        if(i>=n)    return 1;
        if(dp[i] != -1) return dp[i];

        int takeOne=0;
        int takeTwo=0;
        if(s[i] != '0') takeOne=solve(i+1, s);
        if(s[i] != '0' && i+1<n){
            int val=(s[i]-'0')*10+(s[i+1]-'0');
            if(val<=26) takeTwo=solve(i+2, s);
        }
        
        return dp[i]=takeOne + takeTwo;
    }
    int numDecodings(string s) {
        n=s.size();

        dp.assign(n, -1);
        return solve(0, s);
    }
};