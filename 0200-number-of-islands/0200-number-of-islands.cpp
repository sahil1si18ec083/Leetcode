class Solution {
public:
    void dfs(vector<vector<char>>& grid, int& totalislands, int i, int j, int n,
             int m) {

        if(i<0 || j<0 || i>=n || j>=m){
            return ;
        }        
        if (grid[i][j] == '0') {
            return;
        }
        
        grid[i][j] = '0';
        // call four calls in four directions

        dfs(grid, totalislands, i - 1, j, n, m);
        dfs(grid, totalislands, i + 1, j, n, m);
        dfs(grid, totalislands, i, j - 1, n, m);
        dfs(grid, totalislands, i, j + 1, n, m);
    }
    int numIslands(vector<vector<char>>& grid) {

        int totalislands = 0;
        int n = grid.size();    // n=4
        int m = grid[0].size(); // m=5

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j]=='1'){
                    totalislands++;

                    dfs(grid, totalislands, i, j, n, m);

                }
                
            }
        }

        return totalislands;
    }
};