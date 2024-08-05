/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function (nums) {
    const prefixproduct = [];
    const suffixproduct = [];
    let product = 1;
    for (let i = 0; i < nums.length; i++) {
        prefixproduct.push(product)
        product = product * nums[i]
    }
    product = 1;
    for (let i = nums.length - 1; i >= 0; i--) {
        suffixproduct.unshift(product)
        product = product * nums[i]
    }
    const ans = []
    for (let i = 0; i < prefixproduct.length; i++) {
        ans.push(prefixproduct[i] * suffixproduct[i])
    }
    return ans
};