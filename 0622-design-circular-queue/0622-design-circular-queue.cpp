class MyCircularQueue {
private:
    vector<int> v;
    int rear = 0;
    int front = 0;
    int cnt = 0;
    int size = 0;
public:
    MyCircularQueue(int k) {
        size = k;
        v.resize(k);
    }
    
    bool enQueue(int value) {
        if(cnt >= size) return false;
        v[rear] = value;
        rear = (rear + 1) % size;
        cnt++;
        return true;
    }
    
    bool deQueue() {
        if(cnt == 0) return false;
        front = (front + 1) % size;
        cnt--;
        return true;
    }
    
    int Front() {
        if(cnt == 0) return -1;
        return v[front];
    }
    
    int Rear() {
        if(cnt == 0) return -1;
        return v[(rear-1+size) % size];
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return cnt == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */