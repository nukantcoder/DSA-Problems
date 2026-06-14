class StockSpanner {
public:
stack <pair<int,int>> st; // Another approach could be simply the intuition is to find the index of previous greater element on left and  using a monotonic stack
int i = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int span = 0;
        while(!st.empty() && price >= st.top().first)
        {
            st.pop();
        }
        if(st.empty())
        {
            span = i - (-1);
        }
        else
        {span = i - st.top().second;
        }
        st.push({price,i});
        i = i + 1;

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */