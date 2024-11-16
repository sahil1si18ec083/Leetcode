class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();
        int count = 1;

        for (int i = 1; i < k; i++) {
            if (nums[i] - nums[i - 1] == 1) {
                count++;
            }
            else{
                count=1;
            }
        }
        if (count == k) {
            result.push_back(nums[k - 1]);

        } else {
            result.push_back(-1);
        }
        int i = 0;
        int j = k - 1;
        while (j < n - 1) {
            if (count==k) {
                count--;
            }
            i++;
            j++;
            if(nums[j]-nums[j-1]==1){
                count++;
            }
            else{
                count=1;
            }
            
            if (count == k) {
                result.push_back(nums[j]);
            } else {
                result.push_back(-1);
            }
        }

        return result;
    }
};