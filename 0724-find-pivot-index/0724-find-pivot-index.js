/**
 * @param {number[]} nums
 * @return {number}
 */
var pivotIndex = function(nums) {
    // let me check for all the array elements
    // check from start to end
    let sum = nums.reduce((acc,current)=>{
        return acc+ current;
    })
    let rsum = sum- nums[0];
    let lsum=0;
    // this is lsum and rsum for the 0-th index element
    for(let i=0;i<nums.length;i++){
        console.log(lsum,rsum)
        if (lsum==rsum){
            return i;
        }
        lsum = lsum + nums[i];
        rsum = rsum - nums[i+1];

    }
    return -1;
    
};