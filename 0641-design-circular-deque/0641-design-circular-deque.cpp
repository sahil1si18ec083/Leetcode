class MyCircularDeque {
    int q_front;
    int q_rear;
    vector<int> v;
    int capacity;

public:
    MyCircularDeque(int k) {
        q_front = -1;
        q_rear = -1;
        v = vector<int>(k, -1);
        capacity = k;
    }

    bool insertFront(int value) {
        if (q_front == -1 && q_rear == -1) {
            // means the Dequeue was empty
            q_front = 0;
            q_rear = 0;
            v[q_front] = value;
            return true;
        }
        // what if the deque was full already
        if ((q_rear + 1) % capacity == q_front) {
            return false;
        }
        q_front = (q_front - 1 + capacity) % capacity;
        v[q_front] = value;
        return true;
    }

    bool insertLast(int value) {
        if (q_front == -1 && q_rear == -1) {
            // means the Dequeue was empty
            q_front = 0;
            q_rear = 0;
            v[q_rear] = value;
            return true;
        }
        // what if the deque was full already
        if ((q_rear + 1) % capacity == q_front) {
            return false;
        }
        q_rear = (q_rear + 1) % capacity;
        v[q_rear] = value;
        return true;
    }

    bool deleteFront() {
        if (q_front == -1 && q_rear == -1) {
            return  false;
        }
        if(q_front==q_rear){
            // means there is only one element that is empty
            q_front=-1;
            q_rear=-1;
            return true;
        }
        q_front = (q_front + 1) % capacity;
        return true;
    }

    bool deleteLast() {
        if (q_front == -1 && q_rear == -1) {
            return  false;
        }
        if(q_front==q_rear){
            // means there is only one element that is empty
            q_front=-1;
            q_rear=-1;
            return true;
        }
        q_rear=(q_rear-1+capacity)%capacity;
        return true;
    }

    int getFront() {
        if (q_front == -1 && q_rear == -1) {
            return -1;
        }
        return v[q_front];
    }

    int getRear() {
        if (q_front == -1 && q_rear == -1) {
            return -1;
        }
        return v[q_rear];
    }

    bool isEmpty() {
        if (q_front == -1 && q_rear == -1) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if ((q_rear + 1) % capacity == q_front) {
            return true;
        }
        return false;
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