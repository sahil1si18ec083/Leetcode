class Solution {
public:
    int updateCountVector(vector<int>& v, int num) {
        int index = 0;
        while (num != 0) {
            int bit = num & 1;
            if (bit == 1) {
                v[index] += 1;
            }
            num = num >> 1;
            index++;
        }
        int orval = 0;
        for (int i = 0; i < 32; i++) {
            orval = orval + pow(2, i) * v[i];
        }
        return orval;
    }
    int unsetCountVector(vector<int>& v, int num) {
        int index = 0;
        while (num != 0) {
            int bit = num & 1;
            if (bit == 1) {
                v[index] -= 1;
            }
            num = num >> 1;
            index++;
        }
        int orval = 0;
        for (int i = 0; i < 32; i++) {
            orval = orval + pow(2, i) * v[i];
        }
        return orval;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int shortest = INT_MAX;
        int i = 0;
        int j = 0;
        int n = nums.size();
        vector<int> v(32, 0); // this will contain the count of 1s
        int orval = 0;
        while (j < n) {
            orval = updateCountVector(v, nums[j]);
            if(nums[i]>=k){
                return 1;
            }

            while (orval >= k ) {
                shortest = min(shortest, j - i + 1);
                orval = unsetCountVector(v, nums[i]);
                i++;
            }
            j++;
        }
        return (shortest == INT_MAX ? -1 : shortest);
    }
};