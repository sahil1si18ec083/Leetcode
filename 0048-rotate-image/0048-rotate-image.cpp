class Solution {
public:
    void transpose(vector<vector<int>>& matrix, int n){
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        transpose(matrix, n);

        for(int i=0;i<n;i++){
            int l=0;
            int r= n-1;
            while(r>l){
                swap(matrix[i][l], matrix[i][r]);
                l++;
                r--;
            }
        }
        
    }
};