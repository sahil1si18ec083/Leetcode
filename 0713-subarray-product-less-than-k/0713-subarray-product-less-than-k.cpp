class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int result=0;
        int p =1;
        int i=0;
        int j=0;
        int n = nums.size();
        if(k<2){
            return 0;
        }
        while(j<n){
            p= p*nums[j];
            
            while(p>=k){
                p=p/nums[i];
                i++;

            }
            result = result +(j-i+1);
            j++;
        }
        return result;
        
    }
};