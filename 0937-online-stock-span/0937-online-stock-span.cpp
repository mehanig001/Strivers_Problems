class StockSpanner {
public:
    vector<int> v;
    StockSpanner() {
        
    }
    int next(int price) {
        int ct = 1;
        for(int i = v.size()-1; i >= 0; i--){
            if(v[i] > price){
                break;
            }
            ct++;
        }
        v.push_back(price);
        return ct;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */