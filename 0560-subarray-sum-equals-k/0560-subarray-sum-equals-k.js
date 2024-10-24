/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraySum = function(nums, k) {
    var count=0;
    const map = new Map();
    map.set(0,1);
    const n = nums.length;
    let prefixsum=0;
    for(let i=0;i<n;i++){
        prefixsum = prefixsum + nums[i];
        if (map.has(prefixsum-k)){
            count = count + map.get(prefixsum-k);
        
        }
        if (map.has(prefixsum)){
            map.set(prefixsum, map.get(prefixsum)+1)
        }
        else{
            map.set(prefixsum,1)
        }

    }
    return count
};