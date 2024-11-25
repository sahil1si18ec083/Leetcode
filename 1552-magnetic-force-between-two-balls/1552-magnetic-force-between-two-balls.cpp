class Solution {
public:
    bool check(vector<int>& position, int m, int mid) {
        long long int count = 1;
        long long int currentpos = position[0];
        for (long long int i = 1; i < position.size(); i++) {
            long long int diff = position[i] - currentpos;
            if (diff >= mid) {
                count++;
                currentpos = position[i];
            }
        }

        if (count >= m)
            return true;

        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        long long int ans = -1;
        long long int low = 0;
        long long int high = 0;
        for (long long int i = 0; i < position.size(); i++) {
            high += position[i];
        }
        while (low <= high) {
            long long int mid = (low + high) / 2;

            if (check(position, m, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};