class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==0){
            if(n==1){
                return 1;
            }
            return -1;
        }
         

        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < trust.size(); i++) {
            int u = trust[i][0];
            int v = trust[i][1];
            adj[u].push_back(v);
        }
        int res = -1;

        for (int i = 1; i <= n; i++) {
            if (adj.find(i) == adj.end()) {
                res = i;
            }
        }
       
        for (auto i : adj) {
            bool check = false;
            for (int j = 0; j < i.second.size(); j++) {
                int first = i.first;
                if (adj[first][j] == res) {
                    check = true;
                }
            }
            if (check == false) {
                return -1;
            }
        }

        return res;
    }
};