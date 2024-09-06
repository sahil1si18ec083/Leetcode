/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {number} m
 * @param {number} n
 * @param {ListNode} head
 * @return {number[][]}
 */
var spiralMatrix = function (m, n, head) {

    const matrix = []
    for(let i=0;i<m;i++){

        matrix.push(Array(n).fill(-1))
    }

    var count = 0;
    var left = 0;
    var right = n - 1;
    var top = 0;
    var bottom = m - 1;
    var current = head;
    if (n==1){
        for(let i=0;i<m;i++){
            matrix[i][0]= current.val;
            current = current.next;
        }
        return matrix
    }
    while (count < m * n) {
        for (let i = left; i <= right && count < m * n; i++) {
            matrix[top][i] = current ? current.val : -1;
            if (current) {
                current = current.next;
            }
            else{
                 return matrix
            }

            count++;
        }
        top++;
        for (let i = top; i <= bottom && count < m * n; i++) {
            matrix[i][right] = current ? current.val : -1;
            if (current) {
                current = current.next;
            }
            else{
                 return matrix
            }
            count++;

        }
        right--
        for (let i = right; i >= left && count < m * n; i--) {
            matrix[bottom][i] = current ? current.val : -1;
            if (current) {
                current = current.next;
            }
            else{
                 return matrix
            }
            count++;
           
        }
        bottom--
        for (let i = bottom; i >= top && count < m * n; i--) {
            matrix[i][left] = current ? current.val : -1;
            if (current) {
                current = current.next;
            }
            else{
                return matrix
            }
            count++;
        }
        left++;

    }

    return matrix

};