/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumProduct = function(nums) {
    nums.sort((a,b)=>a-b)
    const n = nums.length;
    console.log({nums})
    console.log(nums[0]*nums[1]*nums[n-1])
    let a= nums[0]*nums[1]*nums[n-1];
    let b = nums[n-1]*nums[n-2]*nums[n-3]
    return (Math.max(a,b))
    
};