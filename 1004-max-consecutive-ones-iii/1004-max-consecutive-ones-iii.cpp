class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxres = 0;
        int i = 0;
        int j = 0;
        int n = nums.size();
        int count = 0;

        while (j < n) {

            if (nums[j] == 0) {
                count++;
            }
            
            while (count > k) {
                if (nums[i] == 0) {
                    count--;
                }
                i++;
            }
            maxres = max(j - i + 1, maxres);

            j++;
        }

        return maxres;
    }
};