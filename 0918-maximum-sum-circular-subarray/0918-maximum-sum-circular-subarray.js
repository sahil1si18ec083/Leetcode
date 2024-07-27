/**
 * @param {number[]} nums
 * @return {number}
 */
function miniumsumkadanes(nums){
    let currentsum=0;
    let minsum = 100000;
    for(let i=0;i<nums.length;i++){
        currentsum= currentsum+ nums[i];
        if (currentsum<minsum){
            minsum=currentsum
        }
        if (currentsum>0){
            currentsum=0
        }
    }
    console.log({minsum})
    return minsum

} 
function normalkadane(nums){
    let currentsum = 0;
    let maxsum = -1245678;

    for (let i = 0; i < nums.length; i++) {

        currentsum = currentsum + nums[i];
        if (currentsum > maxsum) {
            maxsum = currentsum;
        }
        if (currentsum < 0) {
            currentsum = 0;

        }

    }
    return maxsum

}
var maxSubarraySumCircular = function(nums) {
    // in order to find the max of the subarray which is a circular array, 
    // find the minium subarray of the middle part
    // and subtract totalsum - minimum subarray sum of middle part

    let totalsum = nums.reduce((acc,current)=>acc+current,0);

    let minimumsubrray= miniumsumkadanes(nums);
    let maxsum = normalkadane(nums);
    if (totalsum-minimumsubrray==0){
        // means all are negative
        return maxsum;
    }
    return Math.max(maxsum,totalsum-minimumsubrray ) 
    
};