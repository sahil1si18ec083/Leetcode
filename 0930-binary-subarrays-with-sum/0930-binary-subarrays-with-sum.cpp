class Solution {
public:
    int fun(vector<int>&nums, int k){
        if (k<0){
            return 0;
        }
        int i=0;
        int j=0;
        int n = nums.size();
        int sum=0;
        int res=0;
        while(j<n){
            sum += nums[j];
            while(sum>k){
                sum = sum - nums[i];
                i++;
            }
            res+=(j-i+1);
            j++;

        }
        return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return fun(nums, goal)- fun(nums, goal-1);
        
    }
};