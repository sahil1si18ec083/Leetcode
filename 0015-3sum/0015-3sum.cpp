class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;

        int k = n - 1;
        while (i < n - 2) {
            int j = i + 1;
            k = n - 1;
            while (k > j) {
                if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else {
                   
                    vector<int>v;
                    v.push_back(nums[i]);v.push_back(nums[j]);v.push_back(nums[k]);
                    result.push_back(v);
                    while (j < n - 3 && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    while (k>=2 && nums[k] == nums[k - 1]) {
                        k--;
                    }
                    while (i<n-3 && nums[i] == nums[i + 1]) {
                        i++;
                    }
                    j++;
                    k--;
                }
            }
            i++;
        }
        return result;
    }
};