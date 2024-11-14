class Solution {
public:
    int calculate(int days,vector<int>& bloomDay, int m, int k ){
        cout<<days<<endl;
        int calc=0;
        int temp=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=days){
                temp++;
            }
            else{
                calc= calc + (temp/k);
                temp=0;
            }
        }
        calc= calc + (temp/k);
        return calc;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int res=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(calculate(mid,bloomDay, m,k)>=m){
                res= mid;
                high = mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return res;
        
    }
};