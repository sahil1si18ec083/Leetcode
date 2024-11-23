class Solution {
public:
    int calculate(vector<int>& piles,long long int mid){
        int total =0;
        for(int i=0;i<piles.size();i++){
            int rem = piles[i]%mid;
            int val = piles[i]/mid;
            if(rem==0){
                total = total + val;
            }
            else{
                total = total + val+1;
            }

        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int ans=-1;

       long long int low=1;
       long long int high=0;
        for(long long int i=0;i<piles.size();i++){
            high+=piles[i];
        }
        while(low<=high){
           long long int mid = (low+high)/2;

            if(calculate( piles,mid)<=h){
                ans = mid;
                high = mid-1;
            }
            else{
                low= mid+1;
            }
        }

        return ans;
        
    }
};