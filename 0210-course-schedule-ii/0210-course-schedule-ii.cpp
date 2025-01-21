class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        int n = numCourses;
        vector<int> indegree(n, 0);
        queue<int> q;
        vector<int> res;

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            mp[v].push_back(u);

            indegree[u]++;
        }
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (q.size() > 0) {
            int front = q.front();
            q.pop();
            res.push_back(front);
            for (auto j : mp[front]) {
                indegree[j]--;
                if (indegree[j] == 0) {
                    q.push(j);
                }
            }
        }

        if (res.size() == n)
            return res;

        return {};
    }
};