class Solution {
public:
    bool iscycle(vector<bool>& visited, 
                 vector<bool>& dfsvisited, vector<int>& result, int n, int i,
                 vector<vector<int>>& graph) {
        visited[i] = true;
        dfsvisited[i] = true;

        for (auto j : graph[i]) {

            if (visited[j] == false &&
                iscycle(visited, dfsvisited, result, n, j,
                        graph)) {
                
                return true;
            } else if (visited[j] == true && dfsvisited[j] == true) {
                
                return true;
            }
        }
        dfsvisited[i] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
       
        vector<bool> visited(n, false);
        vector<bool> dfsvisited(n, false);
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (visited[i] == true) {
                continue;
            } else if (visited[i] == false) {
                iscycle(visited, dfsvisited, result, n, i,
                        graph);
            }
        }
        for (int i = 0; i < n; i++) {
            if (dfsvisited[i] == false) {
                result.push_back(i);
            }
        }
        return result;
    }
};