/**
 * @param {number[]} weights
 * @param {number} days
 * @return {number}
 */
var shipWithinDays = function (weights, days) {
    function ispossible(mid, weights, days) {
        let daycount=1;
        let sum=0;
        for(let i=0;i<weights.length;i++){
            if (sum+weights[i]<=mid){
                sum = sum + weights[i]

            }
            else{
                daycount++;
                sum = weights[i]
                if (daycount>days){
                    return false
                }
            }
        }
        return true

    }

    let low = Math.max(...weights);
    let high = weights.reduce((acc, current) => acc + current, 0);
    let res = -1;
    while (low <= high) {
        let mid = Math.floor((low + high) / 2);
        if (ispossible(mid, weights, days)) {
            res = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return res;

};