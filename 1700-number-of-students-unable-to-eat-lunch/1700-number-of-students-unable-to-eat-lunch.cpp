class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            st.push(sandwiches[i]);
        }
        queue<int> q;
        for(int &std: students){
            q.push(std);
        }
        while(!q.empty()){
            int sz=q.size();
            bool flag=true;
            while(sz--){
                int std=q.front();
                q.pop();
                if(!st.empty() && std==st.top()){
                    flag=false;
                    st.pop();
                }else{
                    q.push(std);
                }
            }
            if(flag && !q.empty())  return q.size();
        }

        return 0;
    }
};