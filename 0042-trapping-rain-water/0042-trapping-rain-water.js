/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function (height) {
    const n = height.length;
    let low = 0;
    let right = n - 1;
    let lmax = 0;
    let rmax = 0;
    let area=0;
    while (low <= right) {
        if (height[low] <= height[right]) {

            if (height[low] >= lmax) {
                lmax = height[low]
            }
            else {
                area = area + lmax - height[low];
            }
            low++;
        }
        else {
            if (height[right] >= rmax) {
                rmax = height[right]
            }
            else {
                area = area + rmax - height[right];
            }
            right--;

        }

    }
    return area;

};