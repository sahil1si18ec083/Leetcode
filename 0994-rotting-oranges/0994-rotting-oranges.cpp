class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int freshcount = 0;
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshcount++;
                }
            }
        }
        if(freshcount==0) return 0;
        while (q.size() > 0) {
            bool rotted= false;

            pair<int, int> front = q.front();
            q.pop();
            int x = front.first;
            int y = front.second;
            cout << x << "x " << y << " y" << endl;

            if (x - 1 < 0 || grid[x - 1][y] == 0 || grid[x - 1][y] == 2) {

            } else {
                // cout << "a" << endl;
                grid[x - 1][y] = 2;
                freshcount--;
                q.push({x - 1, y});
               rotted= true;
            }
            if (y - 1 < 0 || grid[x][y - 1] == 0 || grid[x][y - 1] == 2) {

            } else {
                grid[x][y - 1] = 2;
                freshcount--;
                q.push({x, y - 1});
                 rotted= true;
            }

            if (x + 1 >= m || grid[x + 1][y] == 0 || grid[x + 1][y] == 2) {

            } else {
                // cout << "a" << endl;
                grid[x + 1][y] = 2;
                freshcount--;
                q.push({x + 1, y});
                rotted= true;
            }

            if (y + 1 >= n || grid[x][y + 1] == 0 || grid[x][y + 1] == 2) {

            } else {
               
                grid[x][y + 1] = 2;
                freshcount--;
                q.push({x, y + 1});
                 rotted= true;
            }
            if( rotted){
                res++;
            }
        }
       

        if (freshcount == 0)
            return res-1;

        return -1;
    }
};