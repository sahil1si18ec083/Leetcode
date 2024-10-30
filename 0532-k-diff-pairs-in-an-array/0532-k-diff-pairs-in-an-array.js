/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findPairs = function (nums, k) {
    const n = nums.length;
    const map = new Map();
    for (let i = 0; i < n; i++) {
        if (map.has(nums[i])) {
            map.set(nums[i], map.get(nums[i]) + 1)
        }
        else { map.set(nums[i], 1) }



    }
    let count = 0;
    let res = 0;
    if (k == 0) {
        map.forEach((value, key) => {
            if(value>1 ){
                res++;
            }

        })
        return res


    }
    map.forEach((value, key) => {
        console.log(key)

        if (map.has(key + k)) {
            count++;

        }
        if (map.has(key - k)) {
            count++;

        }
    })

    return count / 2;

};