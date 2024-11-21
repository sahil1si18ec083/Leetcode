class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int count=0;
        int p=1;
        int n = nums.size();
        if(k==0)  return 0;
        while(j<n){
            p= p*nums[j];
            while(p>=k){
                p= p/nums[i];
                i++;
            }
            count = count + (j-i+1);
            j++;
        }
        return count;
    }
};