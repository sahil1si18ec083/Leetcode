class Solution {
public:
    void dfs(int i, int j, int m, int n, int& total,
             vector<vector<char>>& grid) {
        if (i < 0 || i >= n) {
            return;
        }
        if (j < 0 || j >= m) {
            return;
        }

        if (grid[i][j] =='0') {
            return;
        }

        grid[i][j] = '0';

        dfs(i-1, j, m, n, total,grid );
        dfs(i+1, j, m, n, total,grid );
        dfs(i, j-1, m, n, total,grid );
        dfs(i, j+1, m, n, total,grid );

    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid[0].size();    // m=4
        int n = grid.size(); // n=4
        int total = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '1') {
                    dfs(i, j, m, n, total, grid);
                    total++;
                }
            }
        }
        return total;
    }
};