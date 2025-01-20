class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        // let me first create mapping of value in mat vs the x and y coordinate

        int n = mat.size();
        unordered_map<int, vector<int>>
            mp; // value in mat vs the x and y coordinate

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vector<int> temp;
                int  val = mat[i][j];

                temp.push_back(i);
                temp.push_back(j);

                mp[val] = temp;


            }
        }
        unordered_map<int, int> count;
        for(int i=0;i<arr.size();i++){
            int val = arr[i];
            vector<int> temp = mp[val];
            int x = temp[0];
            int y = temp[1];
            cout<<x<<" "<<y <<endl;

            count[x]++;
            count[y+n]++;
            if(count[x]==n ||   count[y+n]==n){
                return i;
            }
            


        }
        return -1;
    }
};