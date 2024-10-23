class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int possibleans = 0;
        while (low <= high) {
            int mid = high + (low - high) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                possibleans = mid + 1;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return possibleans;
    }
};