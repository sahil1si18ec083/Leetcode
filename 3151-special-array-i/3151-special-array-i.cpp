class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            int first = nums[i] ;
            int second = nums[i+1];
            if((first%2==0 && second%2==0) || (first%2==1 && second%2==1)){
                return false;
            }

        }
        return true;
    }
};