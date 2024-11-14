class Solution {
public:
    long long calculate(long long mid, vector<int>& time) {
        long long trips = 0;
        for (long long i = 0; i < time.size(); i++) {
            trips += mid/time[i];
        }
        return trips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {

        long long low = 1;
        long long high = 0;
        long long ans=-1;
        for (long long i = 0; i < time.size(); i++) {
            high += time[i];
        }
        high = high * totalTrips ;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (calculate(mid, time) >= totalTrips) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};