class StockSpanner {
public:
    //T.C->O(N) and s.c-O(N)  optimal approach
    stack<pair<int, int>> st;
    // stack<int> temp;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;
        while(!st.empty() && price>=st.top().first){
            span+=st.top().second;
            st.pop();
        }
        st.push({price, span});
        
        return st.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */