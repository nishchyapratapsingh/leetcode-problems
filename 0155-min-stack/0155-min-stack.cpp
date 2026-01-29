class MinStack {
    stack<long long> s;
    long long mini;

public:
    void push(int val) {
        if (s.empty()) {
            s.push(0);
            mini = val;
        }
        else {
            s.push(val - mini);
            mini = val < mini ? val : mini;
        }
    }
    
    void pop() {
        long long diff = s.top();
        if (diff >= 0) {
            s.pop();
        }
        else {
            mini = mini - diff;
            s.pop();
        }
    }
    
    int top() {
        if (s.top() >= 0) {
            return mini + s.top();
        }
        else {
            return mini;
        }
    }
    
    int getMin() {
        return mini;
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