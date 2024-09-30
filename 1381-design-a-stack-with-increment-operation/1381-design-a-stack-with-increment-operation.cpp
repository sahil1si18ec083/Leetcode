class CustomStack {
    vector<int> v1;
    int mymaxsize;
    int size;

public:
    CustomStack(int maxSize) {
        mymaxsize= maxSize;
        size=0;


    }

    void push(int x) {
        if(size<mymaxsize){
            v1.push_back(x);
            size++;

        }
    }

    int pop() {
        if(size==0){
            return -1;
        }
        int temp = v1[v1.size()-1];
        v1.pop_back();
        size--;
        return temp;
    }

    void increment(int k, int val) {
        if(size<k){
            for(int i=0;i<v1.size();i++){
                v1[i]= v1[i]+val;
            }
        }
        else{
            for(int i=0;i<k;i++){
                v1[i]= v1[i]+val;

            }
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