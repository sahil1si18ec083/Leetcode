/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function (nums) {
    function merge(nums, low, mid, high) {
        const temp = [];
        let i = low;
        let j = mid+1;
        while (i <= mid  && j <= high) {
            if (nums[i] <= nums[j]) {
                temp.push(nums[i]);
                i++;
            }
            else {
                temp.push(nums[j]);
                j++;

            }
        }
        while (i <= mid ) {
            temp.push(nums[i]);
            i++;

        }
        while (j <= high) {
            temp.push(nums[j]);
            j++
        }
        let k = 0;
        for (let it = low; it <= high; it++) {
            nums[it] = temp[k];
            k++;
        }

    }
    function mymergesort(nums, low, high) {
        console.log(low,high)
        if (low >= high) {
            return;
        }
        let mid = Math.floor((low + high) / 2);
        mymergesort(nums, low, mid );
        mymergesort(nums, mid+1, high);
        merge(nums, low, mid, high)


    }
    const n = nums.length;
    mymergesort(nums, 0, n - 1);
    return nums


};