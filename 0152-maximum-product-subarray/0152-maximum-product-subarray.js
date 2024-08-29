/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function(nums) {
    let maxProduct=-12345;
   
    for (let i=0;i<nums.length;i++){
                let product=1;
        for (let j=i;j<nums.length;j++){
            product=product*nums[j];
            if(product>maxProduct){
                maxProduct=product;
            }
    

        }
    }
    return maxProduct;
    
};