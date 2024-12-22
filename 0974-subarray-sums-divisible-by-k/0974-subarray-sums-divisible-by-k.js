/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraysDivByK = function (nums, k) {
    const map = new Map();

    const n = nums.length;

    map.set(0, 1);
    let res = 0;

    let prefixsum = 0;

    for (let i = 0; i < n; i++) {
        prefixsum += nums[i];

        let rem = prefixsum % k;
        if(rem<0){
            rem = rem + k;
        }

        if (map.has(rem)) {
            res = res + map.get(rem);
            map.set(rem, map.get(rem) + 1);

        }
        else {

            map.set(rem, 1);
        }

    }
    return res;

};