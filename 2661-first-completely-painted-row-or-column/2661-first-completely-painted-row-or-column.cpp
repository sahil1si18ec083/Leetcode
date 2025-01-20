class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        // let me first create mapping of value in mat vs the x and y coordinate

        int n = mat.size();
        int m = mat[0].size();
        unordered_map<int, vector<int>>
            mp; // value in mat vs the x and y coordinate
            vector<int> rows(n,0);
            vector<int> columns(m,0);


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m;j++) {
                vector<int> temp;
                int  val = mat[i][j];
                temp.push_back(i);
                temp.push_back(j);
                mp[val] = temp;
            }
        }
        for(int i=0;i<arr.size();i++){
            int val = arr[i];
            vector<int> temp = mp[val];
            int x = temp[0];
            int y = temp[1];

            rows[x]++;
            columns[y]++;
            if(rows[x]==m ||   columns[y]==n){
                return i;
            }

        }
        return -1;
    }
};