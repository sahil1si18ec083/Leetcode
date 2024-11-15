class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            prefix.push_back(sum);
        }
    }

    int sumRange(int left, int right) {

        return  prefix[right]-(left==0?0:prefix[left - 1])  ;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */