class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] == nums[low] && nums[low] == nums[high]) {
                low++;
                high--;
            } else if (nums[mid] >= nums[low]) {
                // left part sorted hai
                if (target >= nums[low] && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }

            } else {
                if (target >= nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else {

                    high = mid - 1;
                }
            }
        }

        return false;
    }
};