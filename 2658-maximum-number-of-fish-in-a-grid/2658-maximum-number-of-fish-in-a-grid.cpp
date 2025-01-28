class Solution {
public:
    void dfs(vector<vector<int>>& grid, int n, int m, int i, int j, int& sum) {
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        if (grid[i][j] == 0)
            return;

        sum = sum + grid[i][j];
        grid[i][j] = 0;
        for (auto it : directions) {
            int x = i + it[0];
            int y = j + it[1];
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != 0) {
                dfs(grid, n, m, x, y, sum);
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int maxsum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                int sum = 0;
                dfs(grid, n, m, i, j, sum);
                if (sum > maxsum) {
                    maxsum = sum;
                }
            }
        }

        return maxsum;
    }
};