class MovingAverage {
private:
    queue<int> q;
    int s;
    int sum = 0;
public:
    MovingAverage(int size) {
        s = size;
    }
    
    double next(int val) {
        q.push(val);
        sum += val;
        while(q.size() > s) {
            sum -= q.front();
            q.pop();
        }

        return (double)sum / (double)q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */