/**
 * @param {number[]} nums
 * @return {number}
 */
var reversePairs = function (nums) {

    function merge(nums, low, mid, high) {
        const temp = []
        let i = low;
        let j = mid + 1;
        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) {
                temp.push(nums[i])
                i++;
            } else {
                temp.push(nums[j])
                j++;
            }
        }
        while (i <= mid) {
            temp.push(nums[i])
            i++;
        }
        while (j <= high) {
            temp.push(nums[j])
            j++;
        }
        let k = 0;
        for (let it = low; it <= high; it++) {
            nums[it] = temp[k];
            k++; 
        }
    }

function fnCountReversePairs(nums, low, mid, high, count) {
    let i = low;
    let j = mid + 1;
    
    while (i <= mid) {
        while (j <= high && nums[i] > 2 * nums[j]) {
            j++;
        }
        count.val = count.val + (j - (mid + 1)); // Increment count for all valid j values
        i++;
    }
}



    function mergeseort(nums, count, low, high) {

        if (low >= high) {
            return;
        }
        // left part
        let mid = Math.floor((low + high) / 2);
        mergeseort(nums, count, low, mid);
        mergeseort(nums, count, mid + 1, high);

        fnCountReversePairs(nums, low, mid, high,count)

        merge(nums, low, mid, high)


    }

    var count = { val: 0 }
    const n = nums.length;

    mergeseort(nums, count, 0, n - 1)



    return count.val



};