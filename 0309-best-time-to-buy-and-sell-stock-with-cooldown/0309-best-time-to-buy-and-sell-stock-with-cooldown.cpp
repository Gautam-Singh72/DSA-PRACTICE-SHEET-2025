class Solution {
public:
    int n;
    vector<vector<int>> t;
    int solve(int i, int buy, vector<int>& prices){
        if(i>=n)    return 0;
        if(t[i][buy] != -1) return t[i][buy];

        if(buy){
            return t[i][buy]=max(-1*prices[i]+solve(i+1, 0, prices), solve(i+1, 1, prices));
        }

        return t[i][buy]=max(prices[i]+solve(i+2, 1, prices), solve(i+1, 0, prices));
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        t.assign(n, vector<int>(2, -1));
        
        return solve(0, 1, prices);
    }
};