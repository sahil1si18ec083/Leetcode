/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var findKthPositive = function (arr, k) {
    const n = arr.length;
    // writing condition for the missing number to be prresent in the right side

    if (arr[n - 1] - n < k) {
        return k+n
    }

    // what if the missing number lies in the left side

    if (arr[0] > k) {
        return k;
    }

    // now the only condition what if it lies  in the middle of the array

    let low = 0;
    let high = n - 1;
    let val;
    while (low <= high) {
        let mid = Math.floor((low + high) / 2);

        if (arr[mid] - (mid + 1) < k) {
            low = mid + 1;
        }
        else {
            val = mid;
            high = mid - 1;
        }
       
    }
    console.log({ val })

    return arr[val] - (arr[val] - (val + 1) - k + 1);

};