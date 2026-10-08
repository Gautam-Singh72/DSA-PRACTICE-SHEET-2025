class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size(); int left=0;
        stack<char> st;
        string ans="";
        for(int i=0; i<n; i++){
            if(s[i]==')'){
                st.push(s[i]);
                left--;
                if(left==0){
                    string temp;
                    while(!st.empty()){
                        temp+=st.top();
                        st.pop();
                    }
                    reverse(temp.begin(), temp.end());
                    temp.erase(0,1);
                    temp.pop_back();
                    ans+=temp;
                }
            }else{
                st.push(s[i]);
                left++;
            }
        }
        return ans;
    }
};