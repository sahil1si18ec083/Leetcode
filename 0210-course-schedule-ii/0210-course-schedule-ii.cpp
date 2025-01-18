class Solution {
public:
    bool iscycle(vector<bool>& visited, unordered_map<int, vector<int>>& adj,
                 vector<bool>& inrecursionvisited, int n, int i,
                 stack<int>& mystack) {
        visited[i] = true;
        inrecursionvisited[i] = true;
        for (auto j : adj[i]) {
            if (visited[j] == false &&
                iscycle(visited, adj, inrecursionvisited, n, j, mystack)) {

                return true;
            } else if (visited[j] && inrecursionvisited[j]) {

                return true;
            }
        }
        mystack.push(i);
        inrecursionvisited[i] = false;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> emptyresult;
        vector<int> result;
        stack<int> mystack;
        vector<bool> visited(n, false);
        vector<bool> inrecursionvisited(n, false);
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        for (int i = 0; i < n; i++) {
            if (visited[i] == true) {
                continue;
            }
            if (visited[i] == false &&
                iscycle(visited, adj, inrecursionvisited, n, i, mystack)) {
                return emptyresult;
            }
        }
        cout << mystack.size() << endl;
        while (mystack.size() > 0) {
            result.push_back(mystack.top());
            mystack.pop();
        }
        return result;
    }
};