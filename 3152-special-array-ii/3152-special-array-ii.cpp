class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n, 0);

        for (int i = 1; i < n; i++) {
            int sum = nums[i] + nums[i - 1];
            prefix[i] = prefix[i - 1];
            if (sum % 2 == 0) {
                prefix[i] += 1;
            }
        }
        int m = queries.size();
        vector<bool> result(m);
        for (int i = 0; i < m; i++) {
            int start = queries[i][0];
            int end = queries[i][1];

            result[i]= prefix[end]==prefix[start];
        }
        return result;
    }
};