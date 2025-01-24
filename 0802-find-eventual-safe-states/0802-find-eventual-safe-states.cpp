class Solution {
public:
    bool dfs(int i, vector<bool>& visited, vector<bool>& dfsvisited,
             vector<bool>& ispartofcycle, int n, vector<vector<int>>& graph) {
        visited[i] = true;
        dfsvisited[i] = true;
        for (auto j : graph[i]) {
            if (visited[j] == false &&
                dfs(j, visited, dfsvisited, ispartofcycle, n, graph)) {
                ispartofcycle[i] = true;

                return true;
            } else if (visited[j] && dfsvisited[j]) {
                ispartofcycle[i] = true;
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

        vector<bool> ispartofcycle(n, false);

        vector<int> result;

        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                dfs(i, visited, dfsvisited, ispartofcycle, n, graph);
            }
        }
        for(int i=0;i<ispartofcycle.size(); i++){
            if(ispartofcycle[i]==false){
                result.push_back(i);
            }
        }
        return result;

    }
};