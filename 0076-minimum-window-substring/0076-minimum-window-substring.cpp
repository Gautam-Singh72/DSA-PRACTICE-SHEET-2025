class Solution {
public:
    string solve(string &s, string &t){
        int n=s.size();
        int m=t.size();
        unordered_map<char, int> mp;
        int totalWords=0;
        for(char &ch: t){
            mp[ch]++;
            totalWords++;
        }

        int minLen=INT_MAX;
        int idx=-1;

        int start=0, end=0;
        while(end<n){
            mp[s[end]]--;
            if(mp[s[end]]>=0)  totalWords--;
            while(totalWords==0){
                int len=end-start+1;
                if(len<minLen){
                    minLen=len;
                    idx=start;
                }
                mp[s[start]]++;
                if(mp[s[start]]>0)  totalWords++;

                start++;
            }
            end++;
        }

        return minLen==INT_MAX ? "" : s.substr(idx, minLen);   
    }
    string minWindow(string s, string t) {
        return solve(s, t);
    }
};