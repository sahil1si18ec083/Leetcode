/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function (intervals) {
    intervals.sort((a, b) => a[0] - b[0])
    const res = []
    var temp = intervals[0];
    for (let i = 1; i < intervals.length; i++) {
        if (intervals[i][0] >= temp[0] && intervals[i][0] <= temp[1] ) {
            temp[1]= Math.max(temp[1],intervals[i][1])

        }
        else{
            res.push(temp)
            temp= intervals[i]
        }
    }
    res.push(temp)
    return res
};