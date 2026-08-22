class Solution {
public:
    //smart approach t.c-O(n^2) ans s.c-O(1)
    int countPalindrome(int i, int j, string& s){
        int n=s.size();
        int count=0;
        while(i>=0 && j<n && s[i]==s[j]){
            count++;
            i--; j++;
        }

        return count;
    }
    int countSubstrings(string s) {
        int n=s.size();

        int count=0;
        for(int i=0; i<n; i++){
            count+=countPalindrome(i, i, s);
            count+=countPalindrome(i, i+1, s);
        }

        return count;
    }
};