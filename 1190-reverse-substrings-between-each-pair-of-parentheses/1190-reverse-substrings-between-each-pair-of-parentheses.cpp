class Solution {
public:
    string solve(string &s){
        stack<char> st;
        int n=s.size();
        for(int i=0; i<n; i++){
            if(s[i]==')'){
                string temp;
                while(!st.empty() && st.top()!='('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for(char &ch: temp){
                    st.push(ch);
                }
            }else{
                st.push(s[i]);
            }
        }
        string res(st.size(), '\0');
        for(int i=st.size()-1; i>=0; i--){
            res[i]=st.top();
            st.pop();
        }
        return res;
    }
    string reverseParentheses(string s) {
         
        return solve(s);
    }
};