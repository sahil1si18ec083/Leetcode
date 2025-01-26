class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalprofit = 0;
        int n = prices.size();

        for (int i = 1; i < n; i++) {
            if (prices[i] >= prices[i - 1]) {

                totalprofit = totalprofit + prices[i] - prices[i - 1];
            }
        }
        return totalprofit;
    }
};