class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
         vector<long long> remainderarray(60, 0);
        long long count = 0;
        for (long long i = 0; i < time.size(); i++) {
            int rem = time[i] % 60;
            remainderarray[rem]++;
        }
       
        count = count + (remainderarray[0] * (remainderarray[0] - 1) / 2);
        count = count + (remainderarray[30] * (remainderarray[30] - 1) / 2);

        for (int i = 1; i <= 29; i++) {
            count = count + remainderarray[i] * remainderarray[60 - i];
        }
        return count;
        
    }
};