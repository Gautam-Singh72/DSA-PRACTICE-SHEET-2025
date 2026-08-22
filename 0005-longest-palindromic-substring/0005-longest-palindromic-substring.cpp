class Solution {
public:
    int maxLen=0;
    int idx=-1;
    void findLongestPalindrome(int i, int j, string& s){
        int n=s.size();

        while(i>=0 && j<n && s[i]==s[j]){
            int len=(j-i+1);
            if(len>maxLen){
                idx=i; maxLen=len;
            }
            i--; j++;
        }
    }
    string longestPalindrome(string s) {
        int n=s.size();
        for(int i=0; i<n; i++){

            findLongestPalindrome(i, i, s);
            findLongestPalindrome(i, i+1, s);
        }
        if(idx==-1) return "";
        
        return s.substr(idx, maxLen);
    }
};