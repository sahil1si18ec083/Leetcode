class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalsum=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }
        int lsum=0;
        int rsum =totalsum;
        for(int i=0;i<n;i++){
           
            rsum-=nums[i];
            if(lsum==rsum) return i;
             lsum+=nums[i];
        }
        return -1;
        
    }
};