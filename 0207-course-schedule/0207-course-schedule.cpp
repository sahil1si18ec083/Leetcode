class Solution {
public:
    bool iscycle(vector<bool>& visited, vector<bool>& dfsvisited, int n,
                 unordered_map<int, vector<int>>& mp, int i) {

        visited[i] = true;
        dfsvisited[i] = true;

        for (auto j : mp[i]) {
            if (visited[j] == false && iscycle(visited, dfsvisited, n, mp, j)) {
                return true;
            }
            if(visited[j] && dfsvisited[j]){
                return true;
            }
        }
        dfsvisited[i] = false;

        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<bool> visited(n, false);
        vector<bool> dfsvisited(n, false);
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            mp[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            if (visited[i] == true) {
                continue;
            }
            if (iscycle(visited, dfsvisited, n, mp, i)) {
                return false;
            }
        }

        return true;
    }
};