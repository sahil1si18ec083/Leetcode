class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();

        int i = 0;
        int j = 0;
        int zeroscount = 0;
        int res = 0;

        while (j < n) {
            if (nums[j] == 0) {
                zeroscount++;
            }


            while (zeroscount > k) {
                if (nums[i] == 0) {
                    zeroscount--;
                }
                i++;
            }
            
            res = max(res, j - i + 1);

            j++;
            
        }
        return res;
    }
};