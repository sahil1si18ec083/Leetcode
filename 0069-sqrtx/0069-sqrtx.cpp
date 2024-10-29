class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) return x;
        int low=0;
        int high = x/2;
        int res=0;
        while(low<=high){
            int mid = (low+high)/2;
            if (mid <=x/mid){
                res= mid;
                low= mid+1;
            }
            else{
                high =mid-1;

            }
        }
        return res;
        
    }
};