class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        long long res = 0;
        map<int, int> myhashmap;
        long long windowsum = 0;
        for (int i = 0; i < k; i++) {
            myhashmap[nums[i]]++;
            windowsum += nums[i];
        }
        if (myhashmap.size() == k) {
            res += windowsum;
        }
        int i = 0;
        int j = k - 1;
        int n = nums.size();
        while (j < n - 1) {
            j++;
            myhashmap[nums[j]]++;
            windowsum += nums[j];
            myhashmap[nums[i]]--;
            windowsum -= nums[i];
            if (myhashmap[nums[i]] == 0) {
                myhashmap.erase(nums[i]);
            }
            i++;

            if (myhashmap.size() == k) {
                if (windowsum > res) {
                    res = windowsum;
                }
            }
        }
        return res;
    }
};