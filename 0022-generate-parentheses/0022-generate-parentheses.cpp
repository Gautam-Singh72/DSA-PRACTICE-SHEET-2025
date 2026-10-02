class Solution {
public:
    vector<string> res;
    void solve(string &temp, int diff, int n){
        if(temp.size()==2*n){
            if(diff == 0) res.push_back(temp);

            return;
        }

        temp.push_back('(');
        solve(temp, diff+1, n);
        temp.pop_back();

        if(diff>0){
            temp.push_back(')');
            solve(temp, diff-1, n);
            temp.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        string temp="";
        solve(temp, 0, n);
        return res;
    }
};