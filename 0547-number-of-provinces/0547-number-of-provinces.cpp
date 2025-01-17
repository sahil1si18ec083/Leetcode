class Solution {
public:
    void dfs(int n, int i, vector<bool>& visited,
             vector<vector<int>>& isConnected) {
        if (visited[i] == true) {
            return;
        }
        visited[i] = true;
        for (int j = 0; j < isConnected[i].size(); j++) {
            if (j != i && isConnected[i][j] == 1) {
                dfs(n, j, visited, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        int count = 0;

        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (visited[i] == true) {
                continue;
            }
            dfs(n, i, visited, isConnected);
            count++;
        }
        return count;
    }
};