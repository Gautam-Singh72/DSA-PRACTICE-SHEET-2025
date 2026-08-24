class Solution {
public:
    int n;
    vector<int> dp;
    int solve(int i, vector<int>& pref){
        if(i==n-1)  return pref[i];
        if(dp[i] != INT_MIN) return dp[i];

        int take=pref[i] - solve(i+1, pref);
        int skip=solve(i+1, pref);

        return dp[i]=max(take, skip);
    }
    int stoneGameVIII(vector<int>& stones) {
        n=stones.size();
        vector<int> pref(n);
        pref[0]=stones[0];
        for(int i=1; i<n; i++){
            pref[i]=pref[i-1]+stones[i];
        }
        dp.resize(n, INT_MIN);
        return solve(1, pref);
    }
};