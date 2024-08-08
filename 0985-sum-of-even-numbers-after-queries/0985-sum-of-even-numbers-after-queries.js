/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {number[]}
 */
var sumEvenAfterQueries = function (nums, queries) {
    const n = queries.length;
    const res = [];
    let initialsum = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] % 2 == 0) {
            initialsum = initialsum + nums[i];
        }
    }
    for (let i = 0; i < queries.length; i++) {
        console.log(initialsum, i)
        let index = queries[i][1];
        let temp = nums[index]
        let value = queries[i][0];
        if ((value + temp) % 2 == 0) {
            if (temp % 2 == 0) {
                initialsum = initialsum + value

            }
            else {
                initialsum = initialsum + value + temp;

            }
        }
        else {
            if (temp % 2 == 0) {
                initialsum = initialsum - temp
            }
            else {

            }
        }
        res.push(initialsum);
        nums[index]= nums[index] +  value;
    }
    return res

};