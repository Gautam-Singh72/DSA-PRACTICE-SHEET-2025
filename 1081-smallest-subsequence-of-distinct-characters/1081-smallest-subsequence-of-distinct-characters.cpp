class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        vector<bool> visited(26, 0);
        vector<int> lastIndex(26, 0);
        for(int i=0; i<n; i++){
            int idx=s[i]-'a';
            lastIndex[idx]=i;
        }

        string res="";
        for(int i=0; i<n; i++){
            if(!visited[s[i]-'a']){
                while(res!="" && res.back()>s[i] && lastIndex[res.back()-'a']>i){
                    visited[res.back()-'a']=false;
                    res.pop_back();

                }
                res.push_back(s[i]);
                visited[s[i]-'a']=true;
            }
        }

        return res;
    }
};