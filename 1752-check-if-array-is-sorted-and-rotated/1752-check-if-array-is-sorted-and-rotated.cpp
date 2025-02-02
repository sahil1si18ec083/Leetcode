class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();
        int peakcount=0;
        for(int i=0;i<n-1;i++){
            if (nums[i+1]<nums[i]){
                peakcount++;
            }
        }
        if(peakcount==0) return true;
        if(peakcount==1 && nums[n-1]<= nums[0]) return true;
        return false;
        
    }
};