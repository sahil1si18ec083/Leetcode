class Solution {
public:
    bool check(int mid, vector<int>& weights, int days, int n){
        int currentweight=0;
        int calculateddays =1;
        for(int i=0;i<n;i++){
            if(weights[i]>mid) return false;
            if(currentweight+ weights[i]<= mid){
                currentweight+=weights[i];
            }
            else{
                 currentweight=weights[i];
                 calculateddays++;

            }
        }
        if(calculateddays<=days) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = weights[0];
        int high =0;
        int n = weights.size();
        int ans =-1;

        for(int i=0;i<n;i++){
            high+= weights[i];
            low = max(low, weights[i]);
        }

        while(low<=high){
            int mid = (low)+ (high-low)/2;

            if(check(mid, weights, days,n)){
                ans = mid;
                high = mid-1;
            }
            else{
                low  = mid+1;
            }
        }

        return ans;
        
    }
};