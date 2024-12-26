class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {

        unordered_map<int, vector<int>> adj;
        vector<bool> visited(n, false);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while (q.size() > 0) {
            int temp = q.front();
            q.pop();
            if(temp == destination) return true;
            for (int i = 0; i < adj[temp].size(); i++) {
                if( visited[adj[temp][i]] == false){
                    q.push(adj[temp][i]);
                    visited[adj[temp][i]] = true;
                }
            }
        }
        return false;
    }
};