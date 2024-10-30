class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<bool> visited(n, false);
        map<int, vector<int>> adjlist;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0]; // 0
            int v = edges[i][1]; // 1
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        queue<int> q;
        q.push(source);
        while (q.size() > 0) {

            int front = q.front();
            if (front == destination) {
                return true;
            }
            q.pop();
            for(int i=0;i<adjlist[front].size();i++){
                if(!visited[adjlist[front][i]] ){
                    q.push(adjlist[front][i]);
                    visited[adjlist[front][i]]= true;

                }
            }
        }
        return false;
    }
};