class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        int i = 0;
        while (i < n - 2) {
            int low = i + 1;
            int high = n - 1;
            while (low < high) {
                
                if (nums[low] + nums[high] + nums[i] == 0) {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
                    res.push_back(temp);

                    
                    while (low < n - 2 && nums[low] == nums[low + 1]) {
                        low++;
                    }
                    while (high > 0 && nums[high] == nums[high - 1]) {
                        high--;
                    }
                    while (i < n - 3 && nums[i] == nums[i + 1]) {
                        i++;
                    }
                    low++;
                    high--;
                } else if (nums[low] + nums[high] + nums[i] < 0) {
                    low++;
                } else {
                    high--;
                }
            }
            i++;
        }

        return res;
    }
};