class Solution {
public:
    int n;
    vector<int> dp;
    int solve(int i, vector<int>& stone){
        if(i>=n) return 0;
        if(dp[i] != INT_MIN)    return dp[i];

        int res=stone[i]-solve(i+1, stone);

        if(i+1<n)   res=max(res, stone[i]+stone[i+1]-solve(i+2, stone));
        if(i+2<n)   res=max(res, stone[i]+stone[i+1]+stone[i+2]-solve(i+3, stone));

        return dp[i]=res;

    }
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        dp.resize(n, INT_MIN);

        int diff=solve(0, stoneValue);
        
        if(diff == 0)    return "Tie";
        if(diff > 0)     return "Alice";

        return "Bob";
    }
};