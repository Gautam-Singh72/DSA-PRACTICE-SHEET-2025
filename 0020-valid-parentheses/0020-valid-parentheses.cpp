class Solution {
public:
    bool check(char ch, stack<char>& st){
        if(st.empty())  return false;
        if(ch==']' && st.top()=='[')    return true;
        if(ch==')' && st.top()=='(')    return true;
        if(ch=='}' && st.top()=='{')    return true;

        return false;
    }
    bool solve(string &s){
        stack<char> st;
        for(char &ch: s){
            if(ch=='[' || ch=='{' || ch=='('){
                st.push(ch);
            }else{
                if(!check(ch, st))  return false;
                st.pop();
            }
        }

        return st.empty();
    }
    bool isValid(string s) {
        return solve(s);
    }
};