class Solution {
public:
    bool comparetwoArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        if (n != m)
            return false;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
    void rotateRight(vector<int>& arr) {
        int n = arr.size();
        int val = arr[n - 1];
        for (int i = n - 1; i >= 1; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = val;
    }
    bool check(vector<int>& nums) {

        int n = nums.size();
        vector<int> sortednums;
        for (int i = 0; i < n; i++) {
            sortednums.push_back(nums[i]);
        }
        sort(sortednums.begin(), sortednums.end());

        for (int i = 0; i < n; i++) {
            bool flag = true;

            for (int j = 0; j < n; j++) {
                if(nums[j]!=sortednums[(j+i)%n] ){
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                return true;
            }
        }

        return false;
    }
};