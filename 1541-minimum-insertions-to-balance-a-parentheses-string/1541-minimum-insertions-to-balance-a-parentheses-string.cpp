class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();

        stack<char> st;
        int i=0;
        int count=0;
        while(i<n-1){
            if(s[i]==')'){
                if(!st.empty()){
                    if(s[i+1]==')'){
                        i+=2;
                    }else{
                        i++;
                        count++;
                    }
                    st.pop();
                }else{
                    if(s[i+1]==')'){
                        count++;
                        i+=2;
                    }else{
                        count+=2;
                        i++;
                    }
                }
            }else{
                st.push(s[i]);
                i++;
            }
        }

        if(i<n){
            if(s[i]=='('){
                st.push(s[i]);
            }else{
                if(!st.empty()){
                    count++;
                    st.pop();
                }else{
                    count+=2;
                }
            }
        }
        

        
        return count+(st.size()*2);
    }
};