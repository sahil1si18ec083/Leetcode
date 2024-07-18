/**
 * @param {number[]} arr
 * @param {number} k
 * @param {number} threshold
 * @return {number}
 */
var numOfSubarrays = function (arr, k, threshold) {
    let count = 0;
    let sum=0;
    const n = arr.length;
    for (let it = 0; it < k; it++) {
        sum = sum + arr[it]
    }
    let average = Math.floor(sum / k);
    if (average >= threshold) {
        count++
    }
    let i = 0;
    let j = k - 1;
    while (j < n - 1) {
        j++;
        sum = sum + arr[j];
        sum = sum - arr[i];
        i++;
        average = Math.floor(sum / k);
        if (average >= threshold) {
            count++


        }
    }
    return count



    };