class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=2;
        int j=2;
        int n = nums.size();
        while(j<n){
            if(nums[j]!= nums[i-1] ||  nums[j]!= nums[i-2]){
                nums[i]= nums[j];
                i++;
            }
            
            j++;
        }
        cout<<i;
        if(i==2){
            return min(n,2);
        }
        return i;
        
    }
};