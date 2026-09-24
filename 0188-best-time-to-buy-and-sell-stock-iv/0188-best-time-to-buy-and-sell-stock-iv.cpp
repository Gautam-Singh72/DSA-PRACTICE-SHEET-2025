class Solution {
public:
    int n;
    vector<vector<vector<int>>> t;
    int solve(int i, int buy, int k, vector<int>& prices){
        if(k==0)    return 0;
        if(i==n){
            return 0;
        }

        if(t[i][buy][k] != -1)  return t[i][buy][k];


        if(buy){
            return t[i][buy][k]=max(-1*prices[i]+solve(i+1, 0, k, prices), solve(i+1, 1, k, prices));
        }

        
        return t[i][buy][k]=max(prices[i]+solve(i+1, 1, k-1, prices), solve(i+1, 0, k, prices));

    }
    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();
        t.assign(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));

        return solve(0, 1, k, prices);
    }
};