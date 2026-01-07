class MyCircularDeque {
private:
    vector<int> v;
    int front = 0;
    int rear = 0;
    int cnt = 0;
    int size = 0;
public:
    MyCircularDeque(int k) {
        size = k;
        v.resize(size);
        rear = k-1;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;

        front = (front - 1 + size) % size;
        v[front] = value;
        cnt++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        
        rear = (rear + 1) % size;
        v[rear] = value;
        cnt++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;

        front = (front + 1) % size;
        cnt--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;

        rear = (rear - 1 + size) % size;
        cnt--;
        return true;

    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return v[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return v[rear];
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return cnt == size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */