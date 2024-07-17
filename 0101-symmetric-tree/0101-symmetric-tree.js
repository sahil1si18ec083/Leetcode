/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isSymmetric = function (root) {
    if (root == null) {
        return []
    }
    const queue = [];
    queue.push(root)
    const res = []

    while (queue.length > 0) {
        let lengthofqueue = queue.length;
        const arr = [];

        for (let i = 0; i < lengthofqueue; i++) {

            let temp = queue[0];
            arr.push(temp == null ? null : temp.val)
            queue.shift();
            // console.log(temp.left)
            if (temp !== null) {
                queue.push(temp.left);
                queue.push(temp.right)

            }

        }

        res.push(arr)
        let start = 0;
        let end = arr.length - 1;
        while (start <= end) {
            if (arr[start] != arr[end]) {
                return false;
            }
            start++;
            end--
        }
    }

    return true

};  