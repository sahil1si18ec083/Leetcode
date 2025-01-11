class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indegree(n, 0);
        vector<int> empty;
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        vector<int> result;
        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (q.size() > 0) {
            int front = q.front();
            q.pop();
            result.push_back(front);
            for (auto j : adj[front]) {
                indegree[j]--;
                if (indegree[j] == 0) {
                    q.push(j);
                }
            }
        }
        if (result.size() != numCourses) {
            return empty;
        }

        return result;
    }
};