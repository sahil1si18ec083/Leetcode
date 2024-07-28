/**
 * @param {character[][]} matrix
 * @return {number}
 */
var largestRectangleArea = function (heights) {
    function getNextSmaller(heights) {
        const res = new Array(heights.length).fill(heights.length);
        const myStack = []
        for (let i = heights.length - 1; i >= 0; i--) {
            while (myStack.length > 0 && heights[myStack[myStack.length - 1]] >= heights[i]) {
                myStack.pop()
            }
            if (myStack.length > 0 && heights[myStack[myStack.length - 1]] < heights[i]) {
                res[i] = myStack[myStack.length - 1]
            }
            myStack.push(i)
        }
        return res;
    }
    function getPrevSmaller(heights) {
        const res = new Array(heights.length).fill(-1);
        const myStack = []
        for (let i = 0; i <= heights.length - 1; i++) {
            while (myStack.length > 0 && heights[myStack[myStack.length - 1]] >= heights[i]) {
                myStack.pop()
            }
            if (myStack.length > 0 && heights[myStack[myStack.length - 1]] < heights[i]) {
                res[i] = myStack[myStack.length - 1]
            }
            myStack.push(i)
        }
        return res;
    }

    const nextsmaller = getNextSmaller(heights);
    const prevSmaller = getPrevSmaller(heights);

    let maxarea = 0;
    const n = heights.length;
    for (let i = 0; i < n; i++) {
        let leftwidth = i - prevSmaller[i] - 1;
        let rightwidth = nextsmaller[i] - i - 1;
        let width = 1 + leftwidth + rightwidth;
        let area = width * heights[i]
        if (area > maxarea) {
            maxarea = area;
        }
    }
    return maxarea


};
var maximalRectangle = function (matrix) {
    const n = matrix.length;
    const m = matrix[0].length;
    const arr = new Array(m).fill(0);
    let maxarea=0;
    for (let i = 0; i < n; i++) {

        for (let j = 0; j < m; j++) {
            if (matrix[i][j] == "1") {
                arr[j] = arr[j] + 1;
            }
            else {
                arr[j] = 0;
            }
        }
        let area = largestRectangleArea(arr);
        if (area > maxarea) {
            maxarea = area;
        }

    }
    return maxarea

};
