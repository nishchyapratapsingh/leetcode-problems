class MyStack {
    queue<int> q;
public:
    void push(int x) {
        int n = q.size();
        
        q.push(x);
        
        for(int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(!q.empty()) {
            int elem = q.front();
            q.pop();
            return elem;
        }
        return -1;
    }
    
    int top() {
        if(!q.empty()) {
            int elem = q.front();
            return elem;
        }
        return -1;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */