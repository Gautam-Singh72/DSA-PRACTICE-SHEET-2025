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
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        t.assign(n+1, vector<vector<int>>(2, vector<int>(3, -1)));

        //base cases
        for(int i=0; i<=n; i++){
            for(int j=0; j<=1; j++){
                t[i][j][0]=0;
            }
        }
        for(int j=0; j<=1; j++){
            for(int k=1; k<=2; k++){
                t[n][j][k]=0;
            }
        }

        //
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=1; j++){
                for(int k=1; k<=2; k++){
                    if(j){
                        t[i][j][k]=max(-1*prices[i]+t[i+1][0][k], t[i+1][1][k]);
                    }
                    else{
                        t[i][j][k]=max(prices[i]+t[i+1][1][k-1], t[i+1][0][k]);
                    }
                
                }
            }
        }

        return t[0][1][2];
    }
};