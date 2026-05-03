class Solution {
public:
    void rotate(string &s){
        int n=s.size();
        char ch=s[0];
        for(int i=0; i<n-1; i++){
            s[i]=s[i+1];
        }
        s[n-1]=ch;
    }
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int n=s.size();
        for(int k=0; k<n; k++){
            rotate(s);
            if(s==goal) return true;
        }

        return false;
    }
};