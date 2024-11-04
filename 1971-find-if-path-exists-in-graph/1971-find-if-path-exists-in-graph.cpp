class Solution {
public:
    void dfs(int n, int source, int destination, unordered_map<int, vector<int>> &mp,
             bool& flag, vector<bool>& visited) {
        if (source == destination) {
            flag = true;
            return;
        }
        visited[source] = true;
        for (int i = 0; i < mp[source].size(); i++) {
            if (visited[mp[source][i]] == false) {
                dfs(n,mp[source][i], destination, mp, flag, visited);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        unordered_map<int, vector<int>> mp;
        vector<bool> visited(n, false);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        bool flag = false;

        dfs(n, source, destination, mp, flag, visited);

        return flag;
    }
};