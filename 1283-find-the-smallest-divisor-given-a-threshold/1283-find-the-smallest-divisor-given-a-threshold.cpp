class Solution {
public:
    bool check(vector<int>& nums, int threshold, int mid){
       long long int ans=0;
        for(long long int i=0;i<nums.size();i++){
          long long  int rem = nums[i] % mid;
            ans = ans + nums[i]/mid;
            if(rem>0) {
                ans++;
            }
        }
        if(ans<=threshold) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long int low=1;
       long long int high =0;
        long long int n = nums.size();
        for(long long int i=0;i<n;i++){
            high+=nums[i];
        }
      long long  int ans=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(check(nums, threshold, mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
        
    }
};