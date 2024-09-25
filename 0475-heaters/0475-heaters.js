/**
 * @param {number[]} houses
 * @param {number[]} heaters
 * @return {number}
 */

var merge = function (intervals) {
    intervals.sort((a, b) => a[0] - b[0]);
    const res = []
    var temp = intervals[0];
    for (let i = 1; i < intervals.length; i++) {
        if (intervals[i][0] >= temp[0] && intervals[i][0] <= temp[1]) {
            temp[1] = Math.max(temp[1], intervals[i][1])

        }
        else if (intervals[i][0] - temp[1] == 1) {
            temp[1] = intervals[i][1]
        }
        else {
            res.push(temp)
            temp = intervals[i]
        }
    }
    res.push(temp)
    return res
};
var findRadius = function (houses, heaters) {

    houses.sort((a, b) => a - b)
    heaters.sort((a, b) => a - b)
    let low = 0;
    let ans = -1;

    let high = Math.max(houses[houses.length - 1] - houses[0] + (houses[0] - heaters[0]), heaters[heaters.length - 1] - houses[0]);
  
    function isPossible(houses, heaters, mid) {
        const arr = []

        for (let i = 0; i < heaters.length; i++) {
            let val = heaters[i]
            arr.push([val - mid, val + mid])

        }
        let n = houses.length;
        for (let i = 0; i < houses.length; i++) {
            let covered= false;
            for (let j = 0; j < arr.length; j++) {
                if (houses[i] >= arr[j][0] && houses[i] <= arr[j][1]) {
                    covered = true;
                    break;

                }
            }
            if(covered ==false){
                return false;
            }
        }
       
        return true

    }
    while (low <= high) {
        let mid = Math.floor((low + high) / 2);
        if (isPossible(houses, heaters, mid)) {
            ans = mid;
            high = mid - 1
        }
        else {
            low = mid + 1;
        }
    }
    return ans
};