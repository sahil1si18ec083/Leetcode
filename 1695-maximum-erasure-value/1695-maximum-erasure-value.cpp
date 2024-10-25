class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxvalue = 0;
        int i = 0;
        int j = 0;
        int n = nums.size();
        int sum = 0;
        set<int> myset;
        while (j < n) {

            while (myset.find(nums[j]) != myset.end()) {
                myset.erase(nums[i]);
                sum = sum - nums[i];
                i++;
            }
            myset.insert(nums[j]);
            sum = sum + nums[j];
            maxvalue = max(maxvalue, sum);
            j++;
        }
        return maxvalue;
    }
};