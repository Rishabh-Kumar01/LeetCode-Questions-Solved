class MinStack {
private:
    stack<int> main;
    stack<int> min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        main.push(val);
        if(min.empty()) min.push(val);
        else {
            if(min.top() >= val) min.push(val);
        }
    }
    
    void pop() {
        int temp = main.top();
        main.pop();
        if(temp == min.top()) min.pop();
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return min.top();
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