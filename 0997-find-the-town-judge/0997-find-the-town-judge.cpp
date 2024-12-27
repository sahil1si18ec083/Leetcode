class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> trustrelation(n, 0);

        for (int i = 0; i < trust.size(); i++) {
            int u = trust[i][0] - 1;

            int v = trust[i][1] - 1;

            trustrelation[v]++;

            trustrelation[u]--;
        }

        for (int i = 0; i < n; i++) {
            if (trustrelation[i] == n - 1) {
                return i + 1;
            }
        }
        return -1;
    }
};