class Solution {
public:
    bool ispossible(int n, vector<int>& quantities, int k){
        int count=0;
        for(int i=0;i<quantities.size();i++){
            if(quantities[i]%k==0){
                count+= quantities[i]/k;
            }
            else{
                count+= quantities[i]/k+1;
            }
        }
        if(count<=n) return true;
        return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {


        int low=1;
        int high = quantities[0];
        int ans=-1;
        for(int i=0;i<quantities.size();i++){
            high = max(high, quantities[i]);
        }

        while(low<=high){
            int mid= (low+high)/2;
            if(ispossible(n , quantities, mid)){
                ans=mid;
                high = mid-1;

            }
            else{
                low = mid+1;
            }
        }
        return ans;
        
    }
};