/**
 * @param {number[]} arr
 * @return {number}
 */
var peakIndexInMountainArray = function(arr) {
    let low=0;
    let high = arr.length-1;
    while(low<=high){
        let mid = Math.floor((low+high)/2);
        if((mid==0 || arr[mid]>arr[mid-1])  && (mid==arr.length-1 ||  arr[mid]>arr[mid+1])){
            return mid;
        }
        else if (mid==0 || arr[mid]>arr[mid-1]){
            low= mid+1
        }
        else{
            high = mid-1
        }
    }
    return -1
};