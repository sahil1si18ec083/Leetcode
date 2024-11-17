class Solution {
public:
    void reverse(vector<int>& nums, int i, int j){
        while(j>i){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int gola=-1;
        int n = nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                gola = i;
                break;
            }
        }
        if(gola==-1){
             reverse(nums, 0, n-1);
             return ;
        }
        int swapped =-1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[gola]){
                swapped = i;
                break;
            }
        }
        swap(nums[gola], nums[swapped]);
         reverse(nums, gola+1, n-1);
        
    }
};