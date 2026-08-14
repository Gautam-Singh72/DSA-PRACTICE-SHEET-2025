class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();

        vector<int> freq(26, 0);
        int start=0, end=0;
        int maxLen=0;
        while(end<n){
            char ch=s[end];
            freq[ch-'a']++;
            while(freq[ch-'a']>2){
                freq[s[start]-'a']--;
                start++;
            }
            maxLen=max(maxLen, end-start+1);
            end++;
        }

        return maxLen;
    }
};