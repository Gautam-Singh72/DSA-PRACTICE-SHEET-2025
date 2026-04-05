class Solution {
public:
    bool solve(int idx, string &temp, string& s, unordered_map<string, int>& mp , vector<int>& dp){
        if(idx==s.size()){
            return true;
        }
        if(dp[idx]!=-1)   return dp[idx];

        string word="";
        for(int i=idx; i<s.size(); i++){
            word+=s[i];
            if(mp.count(word)){
                if(solve(i+1, temp, s, mp, dp)){
                    return true;
                }
            }
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> mp;
        for(auto it: wordDict){
            mp[it]++;
        }
        int n=s.size();
        vector<int> dp(n+1, -1);
        string temp="";
        return solve(0, temp, s, mp, dp);
    }
};