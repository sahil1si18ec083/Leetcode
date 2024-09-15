/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    // if there is no rotation
    const n = nums.length;
    if (nums[n-1]>=nums[0]){
        return nums[0]
    }
    let low=0;
    let high = n-1;
    while(low<=high){
        let mid = Math.floor((low+high)/2);
        console.log(low,mid,high)
        if ( (mid==0 || nums[mid]<=nums[mid-1]  )  && (mid==n-1 || nums[mid]<=nums[mid+1]) ){
            return nums[mid]
        }
        else if (nums[mid]>=nums[0]){
            // it is in left part
            low=mid+1;
        }
        else{
            high = mid-1;
        }
    }
    // return nums[mid]
};