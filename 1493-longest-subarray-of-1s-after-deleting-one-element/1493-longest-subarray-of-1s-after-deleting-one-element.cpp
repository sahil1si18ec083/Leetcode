class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maximum=0;
        int i=0;
        int j=0;
        int n = nums.size();
        int zeroscount=0;
        while(j<n){
            if(nums[j]==0){
                zeroscount++;
            }
            while(zeroscount>1){
                if(nums[i]==0){
                    zeroscount--;

                }
                i++;
            }
            maximum  = max(maximum , j-i);
            j++;

        }
        return maximum;
        
    }
};