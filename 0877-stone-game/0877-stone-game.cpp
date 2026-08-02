class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(int l, int r, int player, vector<int>& nums){
        if(l>r) return 0;
        if(dp[l][r][player] != -1)  return dp[l][r][player];

        if(!player){
            int left_pick=nums[l]+solve(l+1, r, !player, nums);
            int right_pick=nums[r]+solve(l, r-1, !player, nums);
            return dp[l][r][player]=max(left_pick, right_pick);
        }else{
            int left_pick=nums[l]+solve(l+1, r, !player, nums);
            int right_pick=nums[r]+solve(l, r-1, !player, nums);
            return dp[l][r][player]=(left_pick, right_pick);
        }
        return -1;
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        dp.resize(n, vector<vector<int>>(n, vector<int>(2, -1)));
        int totalScore=accumulate(piles.begin(), piles.end(), 0);
        int score1 = solve(0, n-1, 0, piles);
        int score2=totalScore-score1;

        return score1 > score2;
    }
};