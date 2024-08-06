/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    const n = height.length;
    let low=0;
    let high = n-1;
    let maxarea=0;
    while(low<high){
        let area = Math.min(height[low], height[high])*(high-low)
        maxarea = Math.max(area, maxarea);
        if (height[low]<height[high]){
            low++;
        }
        else{
            high--;
        }
    }
    return maxarea
    
};