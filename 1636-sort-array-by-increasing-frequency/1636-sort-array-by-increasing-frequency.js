/**
 * @param {number[]} nums
 * @return {number[]}
 */
var frequencySort = function (nums) {
    const map = new Map();
    const n = nums.length;
    for (let i = 0; i < n; i++) {
        if (map.has(nums[i])) {
            map.set(nums[i], map.get(nums[i]) + 1)
        }
        else {
            map.set(nums[i], 1)
        }
    }
    console.log(map)
    nums.sort((a, b) => {
        if (map.get(a) != map.get(b)) {
            return map.get(a)- map.get(b)
        }
        else{
            return b-a
        }
        
    })
    return nums

};