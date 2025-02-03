class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int minutes = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int freshoaranges =0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if(grid[i][j]==1){
                    freshoaranges++;
                }
            }
        }
        if(freshoaranges==0) return 0;
        while (q.size() > 0) {
            int size = q.size();
            bool rottened= false;

            for (int k = 0; k < size; k++) {
                pair<int, int> front = q.front();
                q.pop();
                int i = front.first;
                int j = front.second;
                vector<vector<int>> directions = {
                    {-1, 0}, {1, 0}, {0, 1}, {0, -1}};

                for (auto it : directions) {
                    int x = i + it[0];
                    int y = j + it[1];
                    if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.push({x, y});
                        rottened= true;
                        freshoaranges--;
                    }
                }
            }
            if(rottened){
                minutes++;
            }
        }
        if(freshoaranges>0) return -1;
        return minutes;
    }
};