class CustomStack {
    int *arr, tp, n;
public:
    CustomStack(int maxSize) {
        arr = new int[maxSize];
        n = maxSize;
        tp = -1;
    }
    
    void push(int x) {
        if(tp < n-1){
            tp++;
            arr[tp] = x;
        }
    }
    
    int pop() {
        if(tp == -1)return -1;
        auto x = arr[tp];
        tp--;
        return x;
        
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < min(n,k); i++){
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */