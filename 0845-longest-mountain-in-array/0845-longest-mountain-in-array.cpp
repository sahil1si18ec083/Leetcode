class Solution {
public:
    int longestMountain(vector<int>& arr) {

        int n = arr.size();
        int res=0;
        for (int i = 1; i < n - 1; i++) {

            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                // means i got a peak point
                int j = i;
                while (j < n - 1 && arr[j + 1] < arr[j]) {
                    j++;
                }
                int k = i;
                while (k >= 1 && arr[k] > arr[k - 1]) {
                    k--;
                }
               
                if(j-k>=2){
                    res = max(res, j-k+1);
                }
            }
        }
        return res;
    }
};