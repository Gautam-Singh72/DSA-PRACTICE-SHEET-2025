class Solution {
public:
    //t.c->O(n*n)+O(nlog(n)) and s.c-O(n)
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();

        sort(pairs.begin(), pairs.end()); //O(n*log(n))
        int maxLen=1;
        vector<int> dp(n, 1); //O(n) Aux space 
        for(int i=0; i<n; i++){  //O(n)
            for(int j=0; j<i; j++){ //O(n)
                if(pairs[i][0] > pairs[j][1]){
                    dp[i]=max(dp[i], dp[j]+1);
                    maxLen=max(maxLen, dp[i]);
                }
            }
        }

        return maxLen;
    }
};