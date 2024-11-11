class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int dipindex=-1;
        int n = nums.size();
        for(int i=n-1;i>=1;i--){
            if(nums[i-1]<nums[i]){
                dipindex= i-1;
                break;
            }

        }
        if (dipindex==-1){
            // just blinding reverse
            for(int i=0;i<n/2;i++){
                swap(nums[i], nums[n-1-i]);
            }
            return ;
        }
        int swapped=dipindex;
        for(int i=n-1;i>=dipindex+1;i--){
            if(nums[i]>nums[dipindex]){
                swapped= i;
                break;

            }
        }
        swap(nums[dipindex], nums[swapped]);

        reverse(nums.begin()+dipindex+1, nums.end());

        
        
    }
};