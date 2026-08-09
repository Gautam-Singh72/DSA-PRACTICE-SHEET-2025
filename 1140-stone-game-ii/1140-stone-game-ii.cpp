class Solution {
public:
    unordered_map<string, int> dp;
    int n;
    int solve(int i, int player, int M, vector<int>& piles){
        if(i>=n)    return 0;
        string key=to_string(i)+" "+to_string(player)+" "+to_string(M);
        if(dp.count(key))   return dp[key];

        int X=2*M;
        if(!player){
            int take=0; int res=0;
            for(int x=1; x<=X ; x++){
                if(i+x <= n){
                    take+=piles[i+x-1];
                    res=max(res, take+solve(i+x, player^1, max(x, M), piles));
                }
            }
            return dp[key]=res;   
        }else{
            int minScore=INT_MAX;
            for(int x=1; x<=X; x++){
                minScore=min(minScore, solve(i+x, player^1, max(x, M), piles));
            }
            return dp[key]=minScore;
        }
        

        return -1;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        // dp.resize(n, vector<int>(2, -1));

        return solve(0, 0, 1, piles);
    }
};