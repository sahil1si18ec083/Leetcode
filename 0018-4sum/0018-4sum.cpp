class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         int n = nums.size();
        vector<vector<int>> res;
        int i=0;
        sort(nums.begin(), nums.end());

        while (i <= n - 4) {
            int j = i + 1;
            while (j <= n - 3) {
                int low = j + 1;
               int high = n - 1;
                while (low < high) {
                    long long  sum = (long long )nums[low] + nums[high] + nums[i] + nums[j];
                    
                    if (sum ==target) {
                        vector< int > temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        res.push_back(temp);
                        

                        while (low < n - 3 && nums[low] == nums[low + 1]) {
                            low++;
                        }
                        while (high >= 1 && nums[high] == nums[high - 1]) {
                            high--;
                        }
                        while (j < n - 2 && nums[j] == nums[j + 1]) {
                            j++;
                        }
                        while (i < n - 1 && nums[i] == nums[i + 1]) {
                            i++;
                        }
                        low++;
                        high--;

                    } else if (sum <
                               target) {
                        low++;
                    } else {
                        high--;
                    }
                }
                j++;
            }
            i++;
        }
        return res;
    }
};