class Solution {
public:
    //T.C-O(n) and S.C-O(n) rec stack space and O(n) auxillary space
    vector<vector<int>> dp;
    int solve(int l, int r, vector<int>& piles){
        if(l>r) return 0;
        if(dp[l][r] != -1)  return dp[l][r];

        int left_pick=piles[l]-solve(l+1, r, piles);
        int right_pick=piles[r]-solve(l, r-1, piles);

        return dp[l][r]=max(left_pick, right_pick);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        dp.resize(n, vector<int>(n, -1));
        
        int diff=solve(0, n-1, piles);

        return diff > 0;
    }
};