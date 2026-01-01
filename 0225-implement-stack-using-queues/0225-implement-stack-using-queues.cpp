class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
     vector<int> temp;
        while(!q1.empty()) {
            temp.push_back(q1.front());
            q1.pop();
        }
        reverse(temp.begin(), temp.end());
        while(!q2.empty()) {
            temp.push_back(q2.front());
            q2.pop();
        }
       
        for(auto i : temp) q2.push(i);
        int ans = q2.front();
        q2.pop();
        return ans;
    }
    
    int top() {
        
        vector<int> temp;
        while(!q1.empty()) {
            temp.push_back(q1.front());
            q1.pop();
        }
        reverse(temp.begin(), temp.end());
        while(!q2.empty()) {
            temp.push_back(q2.front());
            q2.pop();
        }
       
        for(auto i : temp) q2.push(i);
        
        return q2.front();
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
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