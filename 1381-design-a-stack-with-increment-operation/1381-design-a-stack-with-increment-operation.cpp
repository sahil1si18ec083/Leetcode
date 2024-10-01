class CustomStack {
    vector<int> st;
    int max;
    vector<int> incrementarr;
    int size;

public:
    CustomStack(int maxSize) {
        max = maxSize;
        size = 0;
    }

    void push(int x) {
        if (size < max) {
            st.push_back(x);
            incrementarr.push_back(0);
             size++;
        }
    }

    int pop() {
        if (size == 0) {
            return -1;
        }
        int val = st[st.size() - 1];
        int valincrement = incrementarr[incrementarr.size() - 1];
        if (incrementarr.size() > 1) {
            incrementarr[incrementarr.size() - 2] += valincrement;
        }

        size--;
        st.pop_back();
        incrementarr.pop_back();
        return (val+valincrement);
    }

    void increment(int k, int val) {
        if(st.size()==0){
            return;
        }
        if (st.size() < k) {

            incrementarr[incrementarr.size() - 1] += val;
        } else {
            incrementarr[k - 1] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */