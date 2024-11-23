class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size();

        if (nums[n - 1] >= nums[0]) {
            return nums[0];
        }

        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;

            if ((mid == 0 || nums[mid] <= nums[mid - 1]) &&
                (mid == n - 1 || nums[mid] <= nums[mid + 1])) {
                return nums[mid];
            } else if (nums[mid] >= nums[0]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};