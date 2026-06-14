class StockSpanner {
public:
stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int next) {
        int span = 1;
        while(!st.empty() && next >= st.top().first)
        {
            span = span + st.top().second;
            st.pop();
        }
        st.push({next,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */