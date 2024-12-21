/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function (nums1, m, nums2, n) {


    if (n == 0) return 0;

    if (m == 0) {
        // take elements from array 2 and keep it in arr1
        let k = m + n - 1;

        for (let i = n - 1; i >= 0; i--) {
            nums1[k] = nums2[i];
            k--;
        }


    }
    let i = m - 1;
    let j = n - 1;
    let k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] >= nums2[j]) {
            nums1[k] = nums1[i];
            i--;

        }
        else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

};