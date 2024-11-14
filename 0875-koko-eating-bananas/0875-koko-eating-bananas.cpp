class Solution {
public:
     long long int sum(vector<int>& piles) {
        long long int c = 0;
        for (int i = 0; i < piles.size(); i++) {
            c += piles[i];
        }
        return c;
    }
     long long int calculatehrs(vector<int>& piles, long long  int speed){
         long long int r=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]%speed==0){
                r+=piles[i]/speed;
            }
            else{
                r+=piles[i]/speed+1;
            }
        }
        return r;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int low = 1;
        long long  int high = sum(piles);
        long long  int ans=-1;

        while (low <= high) {
            long long  int mid = (low + high) / 2;
            if(calculatehrs(piles,mid)<=h){
                ans = mid;
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return ans;
    }
};