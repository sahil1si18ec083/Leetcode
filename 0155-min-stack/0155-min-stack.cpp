class MinStack {
    vector<int> myStack;
    vector<int> temp;

public:
    MinStack() {  minval = INT_MAX; }

    void push(int val) {
        myStack.push_back(val);
        minval = min(minval, val);
        temp.push_back(minval);
    }

    void pop() {
        let val = myStack[myStack.size() - 1];
        myStack.pop_back();
        temp.pop_back();
        if (temp.length == 0) {
            minval = INT_MAX;
        } else {
            minval = temp[temp.size() - 1];
        }
        return val;
    }

    int top() { return myStack[myStack.size() - 1]; }

    int getMin() { return temp[temp.size() - 1]; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */