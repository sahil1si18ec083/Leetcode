/**
 * @param {number[]} nums
 * @return {boolean}
 */
function megresort(nums, globalinversions, low, high) {
    if (low >= high) {
        return;
    }
    let mid = Math.floor((low + high) / 2);
    megresort(nums, globalinversions, low, mid);
    megresort(nums, globalinversions, mid + 1, high);
    merge(nums, globalinversions, low, mid, high)

}
function merge(nums, globalinversions, low, mid, high) {
    let i = low;
    let j = mid + 1;
    const temp = [];
    while (i <= mid && j <= high) {
        if (nums[i] <= nums[j]) {
            temp.push(nums[i]);
            i++;
        }
        else {
            temp.push(nums[j]);
             globalinversions.val = globalinversions.val + (mid - i + 1);
            j++;
           
        }
    }
    while (i <= mid) {

        temp.push(nums[i]);
        i++;

    }
    while (j <= high) {

        temp.push(nums[j]);
        j++;

    }
    for (let i = 0; i < temp.length; i++) {
        nums[low] = temp[i];
        low++;
    }

}
var isIdealPermutation = function (nums) {
    const n = nums.length;
    var localinversions = 0;
    for (let i = 0; i < n - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            localinversions++;

        }
    }
    var globalinversions = { val: 0 }

    megresort(nums, globalinversions, 0, n - 1);
  

    return globalinversions.val == localinversions;

};