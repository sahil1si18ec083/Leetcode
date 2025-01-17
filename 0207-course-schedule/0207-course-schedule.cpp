class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        int n = numCourses;
        vector<int> indegree(n, 0);

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            mp[v].push_back(u);
            indegree[u]++;
        }

        vector<int> toposort;

        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (q.size() > 0) {
            int temp = q.front();
            q.pop();
            toposort.push_back(temp);
            for (auto i : mp[temp]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        if(toposort.size()==n) return true;

        return false;
    }
};