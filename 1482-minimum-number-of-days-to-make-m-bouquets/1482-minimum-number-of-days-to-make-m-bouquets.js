/**
 * @param {number[]} bloomDay
 * @param {number} m
 * @param {number} k
 * @return {number}
 */
var minDays = function (bloomDay, m, k) {
    function calculate(mid, bloomDay, m, k) {
        let count = 0;
        let bouquets = 0;
        for (let i = 0; i < bloomDay.length; i++) {
            if (bloomDay[i] <= mid) {
                count++;
            }
            else {
                bouquets = bouquets + Math.floor(count / k);
                count = 0;
            }

        }
        bouquets = bouquets + Math.floor(count / k);
        return bouquets;

    }

    let low = 1;
    let high = Math.max(...bloomDay)
    let res=-1;
    while (low <= high) {
        let mid = Math.floor((low + high) / 2);
        if (calculate(mid, bloomDay, m, k) >= m) {
            res = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return res;
};