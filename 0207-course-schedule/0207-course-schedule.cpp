class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // calculate the top sort using kahn's algorithm

        unordered_map<int, vector<int>> adj;

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
                cout<<"gggggg";
                q.push(i);
            }
        }
        
        while (q.size() > 0) {
            int front = q.front();
            cout<<front;
            q.pop();
            toposort.push_back(front);
            for (int j = 0; j < adj[front].size(); j++) {
                indegree[ adj[front][j]]--;
                if (indegree[ adj[front][j]]== 0) {
                    q.push( adj[front][j]);
                }
            }
        }
        cout<<"j"<<toposort.size()<<"  ddddddddddddddd";
        if (toposort.size() == numCourses)
            return true;

        return false;
    }
};