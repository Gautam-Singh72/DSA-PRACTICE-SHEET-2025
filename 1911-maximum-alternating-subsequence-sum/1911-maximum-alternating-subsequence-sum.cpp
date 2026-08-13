class Solution {
public:
    typedef long long ll;
    int n; // n can goes upto 1e5
    vector<vector<ll>> dp;
    ll solve(int i, bool operation, vector<int>& nums){
        //base case condition
        if(i >= n)  return 0;
        if(dp[i][operation] != -1)  return dp[i][operation];

        //two choices at each index
        //either we pick the current index 
        ll take = (operation == 0) ? nums[i] : -1*nums[i];
        take+=solve(i+1, operation^1, nums);

        //or we skip the curr index to form subsequence
        ll skip = solve(i+1, operation, nums);

        //since we have to find the maximum sum
        return dp[i][operation]=max(take, skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        n=nums.size();
        dp.resize(n, vector<ll>(2, -1));
        ll res=solve(0, 0, nums);

        return res;
    }
};