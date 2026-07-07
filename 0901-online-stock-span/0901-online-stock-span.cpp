class StockSpanner {
public:
    int idx;
    stack<pair<int, int>> st;
    StockSpanner() {
        idx = 0;
    }
    
    int next(int price) {

        while(!st.empty() && st.top().first <= price) st.pop();
        int ans;
        if(st.empty()) ans =  idx + 1;
        else ans = (idx - st.top().second);
        st.push( { price, idx } );
        idx++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */