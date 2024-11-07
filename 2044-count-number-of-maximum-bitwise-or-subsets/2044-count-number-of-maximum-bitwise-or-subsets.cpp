class Solution {
public:
    void helper(vector<int>& nums, int n, int& result, int index, int orvalue,
                int maxor) {
        if (index >= n) {
            if (orvalue == maxor) {
                result++;
            }
            return;
        }
    
        helper(nums, n, result, index + 1, orvalue | nums[index], maxor); // include ki call
        helper(nums, n, result, index + 1, orvalue,
               maxor); // exclude  ki call
        
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxor = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            maxor = maxor | nums[i];
        }
        int result = 0;
        int index = 0;
        int orvalue = 0;

        helper(nums, n, result, index, orvalue, maxor);

        return result;
    }
};