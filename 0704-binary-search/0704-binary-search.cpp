class Solution {
public:
    int binarysearch(vector<int>& nums, int target, int n, int low, int high) {
        if (low > high)
            return -1;
        int mid = (low + high) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            return binarysearch(nums, target, n, mid + 1, high);
        } else {
            return binarysearch(nums, target, n, low, mid - 1);
        }
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        return binarysearch(nums, target, n, low, high);
    }
};