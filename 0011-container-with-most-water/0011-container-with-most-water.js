/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function (height) {
    const n = height.length;

    let maxarea = 0;

    let low = 0;
    let high = n - 1;

    while (low <= high) {
        let area = (high - low) * (Math.min(height[low], height[high]));
        maxarea = Math.max(area, maxarea);
        if (height[low] <= height[high]) {
            low++;
        }
        else {
            high--;
        }

    }


    return maxarea;

};