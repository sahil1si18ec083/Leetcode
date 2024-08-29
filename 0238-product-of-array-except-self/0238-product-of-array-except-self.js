/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    const n = nums.length;
    const result= new Array(n).fill(0);

    let prefixproduct=1;
    let suffixproduct =1;
    for(let i=0;i<n;i++){
        result[i]= prefixproduct;
        prefixproduct= prefixproduct*nums[i];

    }
    for(let i=n-1;i>=0;i--){
        result[i]= result[i]*suffixproduct;
        suffixproduct= suffixproduct*nums[i]
    }
return result    
};