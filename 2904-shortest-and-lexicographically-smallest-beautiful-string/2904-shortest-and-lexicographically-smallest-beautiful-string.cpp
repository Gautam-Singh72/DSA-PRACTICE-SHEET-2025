class Solution {
public:
    string findMin(string &s, string t){
        if(s=="")   return t;

        int n=s.size();
        for(int i=0; i<n; i++){
            if(s[i] != t[i] && s[i]>t[i]){
                return t;
            }
        }
        return s;
    }
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int minLen=INT_MAX;
        int start=0, end=0, count=0;

        while(end<n){
            if(s[end]=='1') count++;

            while(count>k){
                if(s[start]=='1')   count--;
                start++;
            }

            while(count==k && s[start]=='0')    start++;

            if(count==k){
                minLen=min(minLen, end-start+1);
            }
            end++;
        }
        start=0; end=0; count=0;
        string res="";
        while(end < n){
            if(s[end]=='1') count++;

            if(end-start+1 > minLen){
                if(s[start]=='1')   count--;
                start++;
            }
            if(end-start+1==minLen && count==k){
                // res=findMin(res, s.substr(start, end-start+1));
                string curr=s.substr(start, minLen);
                if(res=="" || curr<res){
                    res=curr;
                }
            }
            end++;
        }
        return res;
    }
};