class Solution {
public:
    unordered_map<char, char> mp;
    bool check(char ch, stack<char>& st){
        if(st.empty())  return false;
        
        if(mp[st.top()]==ch)    return true;

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
        vector<vector<char>> brackets={{'[', ']'}, {'{', '}'}, {'(', ')'}};
        for(vector<char>& b: brackets){
            mp[b[0]]=b[1];
        }
        
        return solve(s);
    }
};