class MinStack {
    stack<int> s, mins;
public:
    
    void push(int val) {
        s.push(val);
        if (!mins.empty()) {
            if (val <= mins.top()) {
                mins.push(val);
            }
            return;
        }
        mins.push(val);
    }
    
    void pop() {
        if (!mins.empty() && top() == mins.top()) {
            mins.pop();
        }
        if (!s.empty())s.pop();
    }
    
    int top() {
        return s.empty()?-1: s.top();
    }
    
    int getMin() {
        return mins.empty()?-1:mins.top();
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