class Solution {
public:
    bool helper(vector<int>& piles, long long int n, long long int mid, int h) {
        long long int total = 0;
        for (int i = 0; i < n; i++) {
            int rem = piles[i] % mid;
            if (rem != 0) {
                total++;
            }
            total = total + piles[i] / mid;
        }
        if (total <= h)
            return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int low = 1;
        long long int high = 0;
        long long int ans = -1;
        long long int n = piles.size();
        for (long long int i = 0; i < n; i++) {
            high += piles[i];
        }
        while (low <= high) {
            long long int mid = (low + high) / 2;
            if (helper(piles, n, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};