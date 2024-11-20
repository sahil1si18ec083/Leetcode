class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxsum = INT_MIN;
        int sum = 0;

        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        maxsum = max(maxsum, sum);

        for (int i = k - 1; i >= 0; i--) {
            sum = sum - cardPoints[i];
            sum = sum + cardPoints[i + n - k];
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};