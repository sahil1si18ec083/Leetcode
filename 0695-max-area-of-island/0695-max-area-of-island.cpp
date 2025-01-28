class Solution {
public:
    void dfs( vector<vector<int>>& grid,int i, int j, int n , int m , int &sum){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0){
            return ;
        }
        sum++;
        grid[i][j]=0;

        dfs(grid, i + 1, j, n, m, sum);
        dfs(grid, i - 1, j, n, m, sum);
        dfs(grid, i, j + 1, n, m, sum);
        dfs(grid, i, j - 1, n, m, sum);


    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n  = grid.size();
        int m =  grid[0].size();
        int result =0;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if (grid[i][j]==0){
                    continue;
                }
                int sum =0;
                dfs(grid,i, j, n, m,sum);
                result = max(result, sum);

            }
        }
        return result;
    }
};