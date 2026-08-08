class Solution {
public:
    vector<int> dp;
    int solve(int n){
        if(n<=1)    return 1;
        if(dp[n] != -1) return dp[n];

        int count=0;
        for(int i=0; i<n; i++){
            int L=solve(i);
            int R=solve(n-i-1);
            count+=L*R;
        }

        return dp[n]=count;
    }
    int numTrees(int n) {
        dp.assign(n+1, -1);
        return solve(n);
    }
};