class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();

        vector<vector<int>> t(n, vector<int>(n, false));
        int count=0;
        for(int L=1; L<=n; L++){
            for(int i=0; i+L-1<n; i++){
                int j=i+L-1;
                if(s[i]==s[j] && (L<=2 || t[i+1][j-1])){
                    t[i][j]=true;
                }

                if(t[i][j]) count++;
            }
        }

        return count;
    }
};