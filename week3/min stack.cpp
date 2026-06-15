class MinStack {
    stack<int> val, minSt;
public:
    MinStack() {
    }
    
    void push(int value) {
        val.push(value);
        minSt.push(minSt.empty() ? value : min(value, minSt.top()));
    }
    
    void pop() {
        val.pop();
        minSt.pop();
    }
    
    int top() {
        return val.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
