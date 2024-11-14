class Solution {
public:
    bool ispossible(vector<int>& quantities, int k, int n) {
        int m = quantities.size();
        int count=0;
        for(int i=0;i<m;i++){
            int sum=quantities[i];
            while(sum>=k){
                sum = sum - k;
                count++;

            }
            if(sum>0){
                count++;
                sum=0;
            }

        }
        if(count<=n){
            return true;
        }
        return false;
       
    }
        
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;

        int high = quantities[0];
        for (int i = 0; i < quantities.size(); i++) {
            if (quantities[i] > high) {
                cout<<high<<endl;
                high = quantities[i];
            }
        }
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            cout << mid << endl;
            if (ispossible(quantities, mid, n)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};