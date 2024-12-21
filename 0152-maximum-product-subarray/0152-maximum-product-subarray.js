/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function (nums) {
    let prefixProduct = 1;
    let suffixProd = 1;
    let max=-1000;
    const n = nums.length;
    for (let i = 0; i < n; i++) {
        if (prefixProduct == 0) {
            prefixProduct = 1;
        }
        if (suffixProd == 0) {
            suffixProd = 1;
        }
        prefixProduct = prefixProduct * nums[i];
        suffixProd = suffixProd * nums[n - 1 - i];
        
        max = Math.max(max,prefixProduct, suffixProd )

    }
    return max

};