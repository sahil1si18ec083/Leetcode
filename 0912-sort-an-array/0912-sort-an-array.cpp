class Solution {
public:
    void heapify(vector<int> &nums, int i, int n) {
        int left = 2*i+1 ;
        int right = 2*i +2 ;
        int val = nums[i];
        int index = i;
        if (left <n && nums[left]> nums[index]){
            index = left;
        }
        if (right <n && nums[right]> nums[index]){
            index = right;
        }
        if(i==index){
            return ;
        }
        else{
            swap(nums[i], nums[index]);
            heapify(nums, index, n);
        }
    }
    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();

        for (int i = (n - 2) / 2; i >= 0; i--) {

            heapify(nums, i, n);
        }
        // after doing heapify  starting removing the root
        for(int i=0;i<nums.size();i++){
            cout<<nums[i];
        }
        for(int i= n-1;i>=1;i--){
            swap(nums[0], nums[i]);
            heapify(nums, 0, i);
        }
        return nums;
    }
};