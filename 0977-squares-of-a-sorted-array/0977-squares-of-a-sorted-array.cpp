class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            if (nums[low] * nums[low] < nums[high]* nums[high]) {
                res[n - 1] = nums[high] * nums[high];
                high--;
                n--;

            } else {
                res[n - 1] = nums[low] * nums[low];
                low++;
                n--;
            }
        }
        return res;
    }
};