class Solution {
public:
    int helper(vector<int>& nums, int k){
        if(k<0){
            return 0;
        }
        int count=0;
        int oddcount=0;
        int i=0;
        int j=0;
        int n = nums.size();
        while(j<n){
            if(nums[j]%2==1){
                oddcount++;
            }
            
            while(oddcount>k){
                if(nums[i]%2==1){
                    oddcount--;
                }
                i++;

            }
            count=count+j-i+1;
            j++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k)- helper(nums, k-1);

        
    }
};