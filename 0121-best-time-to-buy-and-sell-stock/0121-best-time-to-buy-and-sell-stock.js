/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
    const n = prices.length;
    let maxselling = prices[n - 1];
    let maxprofit = 0;

    for (let i = n - 2; i >= 0; i--) {
        let profit = maxselling - prices[i];
        if (profit >= maxprofit) {
            maxprofit = profit;
        }
        if (prices[i] >= maxselling) {
            maxselling = prices[i];
        }


    }

    return maxprofit;




};