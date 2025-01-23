class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        int time = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if (fresh == 0)
            return 0;
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            int size = q.size();
            bool visited = false;
            
            for (int i = 0; i < size; i++) {
                pair<int, int> front = q.front();
                q.pop();
                for (int j = 0; j < directions.size(); j++) {
                    int x = front.first + directions[j][0];
                    int y = front.second + directions[j][1];
                    if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != 0 &&
                        grid[x][y] != 2) {
                        visited = true;
                        grid[x][y] = 2;
                        q.push({x, y});
                        fresh--;
                    }
                }
            }
            if(visited){
                time++;
            }
        }
        if (fresh != 0)
            return -1;
        return time;
    }
};