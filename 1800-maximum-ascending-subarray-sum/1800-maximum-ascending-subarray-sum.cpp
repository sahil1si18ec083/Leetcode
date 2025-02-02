class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int currentsum = nums[0];
        int maxsum = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                currentsum += nums[i];
            }
            else{
                currentsum= nums[i];
            }
            maxsum= max(maxsum,currentsum );

        }
        return maxsum;
    }
};