class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();

        vector<int> res(n);
        stack<pair<int, int>> st;
        bool flag=0;
        for(int i=0; i<n; i++){
            if(seq[i]=='('){
                if(st.empty())  st.push({i, 0});
                else st.push({i, st.top().second^1}); 
            }else{
                res[i]=st.top().second;
                res[st.top().first]=st.top().second;
                st.pop();
            }
        }

        return res;
    }
};