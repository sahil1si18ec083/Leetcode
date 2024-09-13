/**
 * @param {number[]} nums
 * @return {boolean}
 */
 function merge(arr,low,mid,high,n,inversionCount){
    let i=low;
    let j=mid+1;
    const res=[]
    let x=0;
    while(i<=mid && j<=high){
        if (arr[i]<arr[j]){
            res.push(arr[i]);
            i++;
        }
        else{
            inversionCount.count = inversionCount.count + (mid-i+1);
           res.push(arr[j]);
            j++; 
        }
        
    }
    while(i<=mid){
        res.push(arr[i]);
        i++;
    }
    while(j<=high){
        res.push(arr[j]);
        j++;
    }
    for(let t=low;t<=high;t++){
        arr[t]= res[x];
        x++;
    }
}
function mergesort(arr,n,low,high,inversionCount){
    if (low>=high){
        return;
    }
    let mid= Math.floor((low+high)/2);
    mergesort(arr,n,low,mid,inversionCount);
    mergesort(arr,n,mid+1,high,inversionCount);
    merge(arr,low,mid,high,n,inversionCount);
} 
var isIdealPermutation = function (nums) {
    var localcounts = 0;
    for (let i = 0; i < nums.length - 1; i++) {
        if (nums[i + 1] < nums[i]) {
            localcounts++;
        }

    }
    const inversionCount = {
        count: 0
    }
    let low = 0;
    const n = nums.length;
    let high = nums.length - 1;
    mergesort(nums, n, low, high, inversionCount);

    return localcounts == inversionCount.count

};