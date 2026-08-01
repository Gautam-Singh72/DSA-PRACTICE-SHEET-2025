class Solution {
public:
    
    bool solve(int l, int r, int score1, int score2, int player, vector<int>& nums){
        if(l>r) return score1>=score2;

        if(!player){
            bool left_pick=solve(l+1, r, score1+nums[l], score2, !player, nums);
            bool right_pick=solve(l, r-1, score1+nums[r], score2, !player, nums);
            return left_pick || right_pick;
        }else{
            bool left_pick=solve(l+1, r, score1, score2+nums[l], !player, nums);
            bool right_pick=solve(l, r-1, score1, score2+nums[r], !player, nums);
            return left_pick && right_pick;
        }

    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        
        return solve(0, n-1, 0, 0, 0, nums);
    }
};