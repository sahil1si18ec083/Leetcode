/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxOperations = function (nums, k) {

    // const map = new Map()
    // for (let i = 0; i < nums.length; i++) {
    //     if (!map.has(nums[i])) {
    //         map.set(nums[i], 1)
    //     }
    //     else {
    //         map.set(nums[i], map.get(nums[i]) + 1)
    //     }
    // }

    // let res = 0;
    // for (let i = 0; i < nums.length; i++) {
    //     if (map.has(k - nums[i]) && map.get(k - nums[i]) > 0) {
    //         if(k-nums[i]==nums[i]){

    //         }
    //         res++;
    //         map.set(nums[i], map.get(nums[i]) - 1)
    //         map.set(k - nums[i], map.get(k - nums[i]) - 1)
    //     }
    // }

    // return res;
    const n = nums.length;
    let low=0;
    let count=0;
    let high = n-1;
    nums.sort((a,b)=>a-b);
    while(low<high){
        if (nums[low]+nums[high]==k){
            count++;
            low++;
            high--;
        }
        else if (nums[low]+ nums[high]<k){
            low++;
        }
        else{
            high--;
        }
    }
    return count;

};