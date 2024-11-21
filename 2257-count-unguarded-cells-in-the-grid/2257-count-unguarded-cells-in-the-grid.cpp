class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {

        ;

        vector<vector<int>> array(m, vector<int>(n, 0));
        int count=0;

        for (int i = 0; i < guards.size(); i++) {
            int a = guards[i][0];
            int b = guards[i][1];
            array[a][b] = 7;
        }
        for (int i = 0; i < walls.size(); i++) {
            int a = walls[i][0];
            int b = walls[i][1];
            array[a][b] = 3;
        }

        for (int i = 0; i < guards.size(); i++) {
            int x = guards[i][0];
            int y = guards[i][1];
            // right mai guard move karega
            for (int k = y + 1; k < n; k++) {
                if (array[x][k] == 3) {
                    break;
                } else {
                    array[x][k] = 1; // 1 matlab guarded
                }
            }
            // left mai kao
            for (int k = y - 1; k >= 0; k--) {
                if (array[x][k] == 3) {
                    break;
                } else {
                    array[x][k] = 1; // 1 matlab guarded
                }
            }
            // nichay  jao
            for (int k = x + 1; k < m; k++) {
                if (array[k][y] == 3) {
                    break;
                } else {
                    array[k][y] = 1; // 1 matlab guarded
                }
            }
            for (int k = x - 1; k >= 0; k--) {
                if (array[k][y] == 3) {
                    break;
                } else {
                    array[k][y] = 1; // 1 matlab guarded
                }
            }
        }
        for (int i = 0; i < array.size(); i++) {
            for (int j = 0; j < array[i].size(); j++) {

                count = count + (array[i][j] == 0 ? 1 : 0);
            }
        }
        return count;
    }
};