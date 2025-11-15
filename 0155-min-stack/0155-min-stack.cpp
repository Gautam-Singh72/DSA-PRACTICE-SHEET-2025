class MinStack {
public:
    stack<int> st;
    stack<int> temp;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(temp.empty()){
            temp.push(val);
        }else{
            temp.push(min(val, temp.top()));
        }
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
        }
        if(!temp.empty()){
            temp.pop();
        }
    }
    
    int top() {
        if(!st.empty()){
           return st.top();
        }
        return -1;
    }
    
    int getMin() {
        if(!temp.empty()){
            return temp.top();
        }
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */