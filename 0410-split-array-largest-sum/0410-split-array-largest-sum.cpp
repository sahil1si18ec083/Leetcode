class Solution {
public:
    bool calculatesubarrays(vector<int>& nums, int mid, int k) {
        int calculatesubarrays = 1;
        int currentsum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i]>mid){
                return false;
            }
           
            if (currentsum + nums[i] <= mid) {
                currentsum += nums[i];
            } else {
                currentsum = nums[i];
                calculatesubarrays++;
            }
        }
        
        if (calculatesubarrays <= k) return true;

        return false;
    }
    int splitArray(vector<int>& nums, int k) {

        int low = INT_MAX;
        int high = 0;
        int ans = -1;

        for (int i = 0; i < nums.size(); i++) {
            high += nums[i];
            low = min(nums[i], low);
        }
        while (low <= high) {
            int mid = (low + high) / 2;
            // cout<<mid<<endl;

            if (calculatesubarrays(nums, mid, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};