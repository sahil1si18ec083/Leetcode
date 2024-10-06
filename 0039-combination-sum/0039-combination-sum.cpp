class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<int>& temp,
                vector<vector<int>> &result, int idx) {
        if (idx >= candidates.size()) {
            if (target == 0) {
                result.push_back(temp);
            }
            return;
        }
        if (target >= candidates[idx]) {
            temp.push_back(candidates[idx]);
            helper(candidates, target - candidates[idx], temp, result, idx);
            temp.pop_back();
        }
        // exclude call
        helper(candidates, target, temp, result, idx + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> result;
        helper(candidates, target, temp, result,0);
        return result;
    }
};