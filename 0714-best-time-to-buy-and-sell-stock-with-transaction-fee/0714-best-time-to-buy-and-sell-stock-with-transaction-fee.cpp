class Solution {
public:
    int n;
    vector<vector<int>> t;
    int solve(int i, int buy, int fee, vector<int>& prices){
        if(i>=n)    return 0;
        if(t[i][buy] != -1) return t[i][buy];

        if(buy){
            return t[i][buy]=max(-1*prices[i]+solve(i+1, 0, fee, prices), solve(i+1, 1, fee, prices));
        }

        return t[i][buy]=max(-1*fee+prices[i]+solve(i+1, 1, fee, prices), solve(i+1, 0, fee, prices));
    }
    int maxProfit(vector<int>& prices, int fee) {
        n=prices.size();
        t.resize(n, vector<int>(2, -1));
        return solve(0, 1, fee, prices);
    }
};