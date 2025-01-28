class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int totalparameter = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                vector<vector<int>> directions = {
                    {-1, 0}, {1, 0}, {0, 1}, {0, -1}};
                for (auto it : directions) {
                    int x = i + it[0];
                    int y = j + it[1];
                    if (x < 0 || x >= n || y< 0 || y>= m || grid[x][y] == 0) {
                         totalparameter++;
                    }
                }
            }
        }

        return totalparameter;
    }
};