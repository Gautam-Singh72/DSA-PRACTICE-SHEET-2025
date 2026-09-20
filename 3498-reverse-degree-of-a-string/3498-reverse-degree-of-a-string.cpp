class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int res=0;
        for(int i=0; i<n; i++){
            int mul=26-(s[i]-'a');

            res+=mul*(i+1);
        }

        return res;
    }
};