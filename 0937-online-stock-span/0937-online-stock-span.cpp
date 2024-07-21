class StockSpanner {
    stack<pair<int,int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.empty() || st.top().first > price){
            st.push({price,1});
            return 1;
        }
        else{
            int ct = 1;
            while(!st.empty() && st.top().first <= price){
                ct+=st.top().second;
                st.pop();
            }
            st.push({price,ct});
            return ct;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */