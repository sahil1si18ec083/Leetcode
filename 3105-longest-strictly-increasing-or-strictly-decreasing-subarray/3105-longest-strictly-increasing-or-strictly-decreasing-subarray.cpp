class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int n = nums.size();
        int prev_value_to_be_compared = nums[0];
        bool isincreasingFlag = true;
        int size = 1;
        int maxsize = 1;

        for (int i = 1; i < n; i++) {

            if (nums[i] == prev_value_to_be_compared) {
                size = 1;

            } else if (nums[i] > prev_value_to_be_compared) {

                if (isincreasingFlag) {
                  size++;
                } else {
                    size = 2;
                }
                  isincreasingFlag = true;

            } else {
                if (!isincreasingFlag) {
                    size++;
                } else {
                    size = 2;
                }
                 isincreasingFlag = false;
            }
            maxsize = max(maxsize, size);
            prev_value_to_be_compared = nums[i];
        }
        return maxsize;
    }
};