class Solution {
public:
    bool search(vector<int>& arr, int val) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == val) {
                return true;
            } else if (arr[mid] == arr[low] && arr[low] == arr[high]) {
                low++;
                high--;
            }
            // left part sorted hai
            else if (arr[mid] >= arr[low]) {
                if (val >= arr[low] && val <= arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // toh matlab right part sorted hoga
            else {
                if (val >= arr[mid] && val <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};