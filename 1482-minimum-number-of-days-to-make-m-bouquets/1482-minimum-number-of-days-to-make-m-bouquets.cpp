class Solution {
public:
    bool helper(vector<int>& bloomDay, int m, int k, int mid) {
        int current = 0;
        int count = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                current++;
            } else {
                count = count + (current / k);
                current = 0;
            }
        }
        count = count + (current / k);
        if(count>=m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1;
        int high = bloomDay[0];
        for(int i=0;i<bloomDay.size();i++){
            high = max(high, bloomDay[i]);
        }
        cout<<helper(bloomDay, m, k, high);
        int ans =-1;
        while(low<=high) {
            int mid = (low + high) / 2;
           
            if (helper(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};