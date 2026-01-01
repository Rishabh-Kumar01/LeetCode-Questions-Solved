class MinStack {
private:
    vector<int> v;
    int idx = -1;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        v.push_back(val);
        idx++;
    }
    
    void pop() {
        v.pop_back();
        idx--;
    }
    
    int top() {
        return v[idx];
    }
    
    int getMin() {
        vector<int> temp = v;
        sort(temp.begin(), temp.end());
        return temp[0];
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