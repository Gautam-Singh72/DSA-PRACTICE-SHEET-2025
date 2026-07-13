class Solution {
public:
    bool solve(int i, int j, string &s, string &p){
        if(i<0 && j<0) return true;
        if(j<0 && i>=0) return false;
        if(i<0 && j>=0){
            while(j>=0 && p[j]=='*'){
                j=j-2;
            }
            return j<0;
        }  

        if(s[i]==p[j] || p[j]=='.')  return solve(i-1, j-1, s, p);

        if(p[j]=='*'){
           //agar pichla char 0 time liya to
           bool op1=solve(i, j-2, s, p); 

           //agar pichla wala character ek ya jyada baar lena ho
           bool op2=false;
           if(s[i]==p[j-1] || p[j-1]=='.')
                op2=solve(i-1, j, s, p);
           
           return op1 || op2;
        }  

        //agar p[j] char match hi nahi krta h to return false;

        return false; 
    }
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();

        return solve(m-1, n-1, s, p);
    }
};