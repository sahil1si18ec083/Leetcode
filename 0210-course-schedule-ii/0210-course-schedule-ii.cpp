class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> empty;
        vector<int> toposort;
        int n = numCourses;
        vector<int> indegree(n, 0);

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            indegree[u]++;
            adj[v].push_back(u);
        }

        queue<int> q;

        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (q.size() > 0) {
            int front = q.front();
            q.pop();
            toposort.push_back(front);
            for (auto i : adj[front]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        cout << toposort.size() << endl;
        if (toposort.size() == numCourses)
            return toposort;

        return empty;
    }
};