class Solution {
public:
    int calculateLps(string &s, vector<int>& lps){
        int n=s.size();
        int pre=0; int suff=1;
        while(suff<n){
            if(s[pre] == s[suff]){
                lps[suff]=pre+1;
                pre++;
                suff++;
            }else{
                if(pre==0){
                    lps[suff]=0;
                    suff++;
                }else{
                    pre=lps[pre-1];
                }
            }
        }
        return lps[n-1];
    }
    string shortestPalindrome(string s) {
        string temp=s;
        reverse(temp.begin(), temp.end());
        temp=s+'$'+temp;
        int n=temp.size();
        vector<int> lps(n, 0);
        int len=calculateLps(temp, lps);
        int req=s.size()-len;
        int idx=s.size()-1;
        string res="";
        while(req>0){
            res+=s[idx];
            idx--;
            req--;
        }
        res+=s;
        return res;
    }
};