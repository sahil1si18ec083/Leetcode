class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();    // 5
        int n = matrix[0].size(); // 4
        int low = 0;
        int high = n- 1;

        while (high >= 0 && low <= m - 1) {
            if (matrix[low][high] == target) {
                return true;
            } else if (matrix[low][high] < target) {
                low++;
            } else {
                high--;
            }
        }
        return false;
    }
};