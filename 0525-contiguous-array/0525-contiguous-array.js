/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxLength = function (nums) {
    const map = new Map();
    map.set(0, -1); // initial value of  map has to be set with 0 with index -1

    const n = nums.length;
    let prefixsum = 0;
    let maxlength = 0;
    for (let i = 0; i < n; i++) {
        if (nums[i] == 0) {
            // 0 ko mankar chal ki vo minus 1 hai
            prefixsum = prefixsum - 1

        }
        else {
            prefixsum = prefixsum + 1;

        }
        if (map.has(prefixsum)) {
            maxlength = Math.max(maxlength, i - map.get(prefixsum))
        }
        if (!map.has(prefixsum)) {
            map.set(prefixsum, i)
        }

    }

    console.log(map)
    return maxlength

};