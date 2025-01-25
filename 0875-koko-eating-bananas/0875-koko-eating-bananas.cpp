class Solution {
public:
    long long int calculate(vector<int>& piles, long long int h,
                            long long int mid) {
        long long int total = 0;
        for (int i = 0; i < piles.size(); i++) {
            long long int rem = piles[i] % mid;
            if (rem != 0) {
                total++;
            }
            total = total + (piles[i] / mid);
        }
        if (total <= h)
            return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int low = 0;
        long long int high = 0;

        for (int i = 0; i < piles.size(); i++) {
            
            high = high + piles[i];
        }
        long long int ans = -1;
        while (low <= high) {
            long long int mid = (low + high) / 2;
            cout <<low<< mid << endl;
            if (calculate(piles, h, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};