class Solution {
public:
    int helper(vector<int>& spells, vector<int>& potions, int n , int m, int val,long long  threshold){

        int ans =-1;
        int low =0;
        int high = m-1;
        while(low<=high){
            int mid = (low)+ (high-low)/2;
            long long p = val * potions[mid];
            if(p>=threshold){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        int n = spells.size();
        int m = potions.size();
        vector<int> result(n,0);
        sort(potions.begin(), potions.end());

        for(int i=0;i<n;i++){
              cout<<helper(spells , potions , n, m, spells[i], success)<<endl;
            if(helper(spells , potions , n, m, spells[i], success)!=-1){
               
                result[i]= m- helper(spells , potions , n, m, spells[i], success);
            }
        }

        return result;

        
    }
};