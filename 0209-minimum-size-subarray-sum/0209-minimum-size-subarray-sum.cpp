class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int i=0;
        int j=0;
        int n = nums.size();
        int sum=0;
        int minsize=INT_MAX;
        while(j<n){
            sum += nums[j];
            while(sum>=target){
                minsize= min(minsize, j-i+1);
                sum-=nums[i];i++;
            }
            j++;
        }
        return (minsize==INT_MAX?0:minsize);
    }
};