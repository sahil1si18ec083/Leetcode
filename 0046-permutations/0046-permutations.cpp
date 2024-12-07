class Solution {
public:
    void solve(vector<vector<int>>& result,  int index,
               vector<int>& nums) {
        // base case
        if (index >= nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);
            solve(result, index + 1, nums);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        int n = nums.size();
        int index = 0;
        vector<vector<int>> result;
        solve(result, index, nums);

        return result;
    }
};