class Solution {
public:
    int dx[8]={-2, -1, 1, 2, 2, 1, -1, -2}; int dy[8]={-1, -2, -2, -1, 1, 2, 2, 1};
    bool isValid(int i, int j, int n){
        return i>=0 && i<n && j>=0 && j<n;
    }
    double solve(int i, int j, int k, int n, vector<vector<vector<double>>>& dp){
        if(k==0)    return 1.0;
        if(dp[i][j][k] != -1) return dp[i][j][k];

        double count=0.0;
        for(int l=0; l<8; l++){
            int r=i+dx[l];
            int c=j+dy[l];
            if(isValid(r, c, n)){
                count+=solve(r, c, k-1, n, dp);
            }
        }
        return dp[i][j][k]=count;
    }
    double custom_pow(int n, int k){
        if(k==0)    return 1;

        int binary=k;
        long long mult=n;
        double ans=1;
        while(binary){
            int rem=binary%2;
            if(rem)     ans=ans*mult;
            binary=binary/2;
            mult=mult*mult;
        }
        return ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        double total_pos=pow(8, k);
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k+1, -1)));
        double valid_pos=solve(row, column, k, n, dp);
        double prob=valid_pos/total_pos;

        return prob;
    }
};