class Solution {
public:
    bool helper(vector<int>& position, int m, int n, long long int mid) {
        int balls = 1;
        long long int pos = position[0];

        for (int i = 1; i < n; i++) {
            if (position[i] - pos < mid) {
                // pos = position[i];

            } else {
                balls++;
                pos = position[i];
            }
        }
        if (balls < m)
            return false;
        return true;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        long long int low = 0;
        long long int high = 0;
        int n = position.size();
        for (int i = 0; i < n; i++) {
            high += position[i];
        }
        long long int ans = -1;

        while (low <= high) {
            long long int mid = (low + high) / 2;
           
            if (helper(position, m, n, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return (int)ans;
    }
};