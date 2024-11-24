class Solution {
public:
    bool possible(vector<int>& weights, int mid, int days) {
        int currentweight=0;
        int dayscount=1;
        for (int i = 0; i < weights.size(); i++) {
            if(weights[i]>mid){
                return false;
            }
            if(currentweight+weights[i] <= mid){
                currentweight+=weights[i];
            }
            else{
                dayscount++;
                currentweight=weights[i];
            }

        }
        if(dayscount<=days) return true;

        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int low = 1;
        int high = 0;
        int ans=-1;
        for (int i = 0; i < weights.size(); i++) {
            high += weights[i];
        }
        while (low <= high) {
            int mid = (low + high)/2;

            if (possible(weights, mid,days)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};