/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function (intervals) {
    function max(a, b) {
        if (a >= b) {
            return a;
        }
        else {
            return b;
        }
    }
    const top = [];
    const bottom = [];
    const result = [];
    for (let i = 0; i < intervals.length; i++) {
        top.push(intervals[i][0]);
        bottom.push(intervals[i][1])
    }
    top.sort((a, b) => a - b);
    bottom.sort((a, b) => a - b);


    let temp = [top[0], bottom[0]]
    for (let i = 1; i < intervals.length; i++) {
        if (top[i] <= temp[1]) {
            temp = [temp[0], max(temp[1], bottom[i])]
            console.log(temp)
        }
        else {
            result.push(temp);
            temp = [top[i], bottom[i]]
        }
    }
    console.log(top)
    console.log(bottom)
    result.push(temp);
    return result



};