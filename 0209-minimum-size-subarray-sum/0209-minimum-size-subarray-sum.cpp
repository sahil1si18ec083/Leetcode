class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        map<int, int> mymap;
        int i = 0;
        int j = 0;
        int n = nums.size();
        int minval = INT_MAX;
        while (j < n) {
            sum += nums[j];
            while (sum >= target) {
                minval = min(j - i + 1,minval);
                sum = sum - nums[i];
                i++;
            }
            j++;
        }
        return minval==INT_MAX?0:minval;
    }
};