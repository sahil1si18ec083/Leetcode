class Solution {
public:
    bool helper(vector<int>& nums, int mid, int threshold) {
        int c = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] % mid == 0) {
                c += nums[i] / mid;

            } else {
                c += nums[i] / mid;
                c += 1;
            }
        }
        if (c <= threshold)
            return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {

        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum = max(nums[i], sum);
        }
        int low = 1;
        int high = sum;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (helper(nums, mid, threshold)) {
                ans = mid;
                high = mid - 1;
            } else {

                low = mid + 1;
            }
        }
        return ans;
    }
};