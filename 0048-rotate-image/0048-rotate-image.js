/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    function transpose(matrix){
        const n = matrix.length;
        const m = matrix[0].length;
        for(let i=0;i<n;i++){
            for (let j=i;j<n;j++){
                let temp = matrix[i][j];
                matrix[i][j]= matrix[j][i];
                matrix[j][i]= temp;
            }
        }
    }
    function rotaterow(matrix){
const n = matrix.length;
        const m = matrix[0].length;
        for(let i=0;i<n;i++){
            let start=0;
            let end=m-1;
            while(start<=end){

                let temp = matrix[i][start];
                matrix[i][start]= matrix[i][end];
                matrix[i][end]= temp;
                start++;
                end--;

            }
        }
    }

    transpose(matrix);
    rotaterow(matrix);

    return matrix;
    
};