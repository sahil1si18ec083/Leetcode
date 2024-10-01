class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        vector<long long> remainderarray(24, 0);
        long long count = 0;
        for (long long i = 0; i < hours.size(); i++) {
            int rem = hours[i] % 24;
            remainderarray[rem]++;
        }
       
        count = count + (remainderarray[0] * (remainderarray[0] - 1) / 2);
        count = count + (remainderarray[12] * (remainderarray[12] - 1) / 2);

        for (int i = 1; i <= 11; i++) {
            count = count + remainderarray[i] * remainderarray[24 - i];
        }
        return count;
    }
};