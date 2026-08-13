class Solution {
public:
    static bool compare(string &a, string &b){
        if(a.size() < b.size()) return true;

        return false;
    }
    bool isPredecessor(string &a, string &b){
        int n=a.size();
        int m=b.size();
        if(n-m != 1)    return false;

        int idx=0;
        for(int i=0; i<n; i++){
            if(a[i]==b[idx]){
                idx++;
            }
        }

        return idx == m;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();

        sort(words.begin(), words.end(), compare);
        vector<int> dp(n, 1);
        int maxLen=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(isPredecessor(words[i], words[j])){
                    dp[i]=max(dp[i], dp[j]+1);
                    maxLen=max(maxLen, dp[i]);
                }
            }
        }

        return maxLen;
    }
};