class StockSpanner {
    vector<int> arr;
    stack<int> st;
    int i;
public:
    StockSpanner() {
        i = -1;
    }
    
    int next(int price) {
        arr.push_back(price);
        i++;
        int cnt = 1;

        while (!st.empty() && arr[st.top()] <= price) {
            st.pop();
        }
        if (!st.empty()) cnt = i - st.top();
        else cnt = i+1;
        
        st.push(i);
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */