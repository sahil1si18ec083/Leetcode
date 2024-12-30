class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int low = 0;
        vector<vector<int>> v;

        while (low < n - 2) {
            int i = low + 1;
            int j = n - 1;

            while (j > i) {
                if (nums[low] + nums[i] + nums[j] == 0) {
                    vector<int> temp;
                    temp.push_back(nums[low]);
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    v.push_back(temp);
                    while (low < n - 1 && nums[low] == nums[low + 1]) {
                        low++;
                    }

                    while (i < n - 1 && nums[i] == nums[i + 1]) {
                        i++;
                    }
                    while (j >= 1 && nums[j] == nums[j - 1]) {
                        j--;
                    }
                    i++;
                    j--;
                } else if (nums[low] + nums[i] + nums[j] < 0) {
                    i++;
                } else {
                    j--;
                }
            }
            low++;
        }
        return v;
    }
};