class Solution {
public:
    int getmin(vector<int>&nums){
        int index=0;
        int val = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<val){
                val = nums[i];
                index = i;
            }
        }
        return index;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {

        for (int i = 0; i < k; i++) {
            int minindex = getmin(nums);

            nums[minindex] = nums[minindex] * multiplier;
        }

        return nums;
    }
};