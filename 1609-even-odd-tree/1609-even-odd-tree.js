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
var isEvenOddTree = function (root) {
    const queue = []
    queue.push(root)
    let level = 0;
    while (queue.length > 0) {
        const arr = []
        let queuelength = queue.length;

        for (let i = 0; i < queuelength; i++) {
            const temp = queue[0];
            queue.shift();
            arr.push(temp.val);
            if (temp.left != null) {
                queue.push(temp.left)

            }
            if (temp.right != null) {
                queue.push(temp.right)
            }


        }
        if (level % 2 == 0) {
            if (arr[0] % 2 == 0) {
                return false
            }
            for (let j = 1; j < arr.length; j++) {
                if (arr[j] <= arr[j - 1] || arr[j] % 2 == 0) {
                     return false
                }
            }

        }
        else  {
            if (arr[0] % 2 == 1) {
                return false
            }
            for (let k = 1; k < arr.length; k++) {
                if (arr[k] >= arr[k - 1] || arr[k]%2==1) {
                    return false
                }
            }
        }
        level++;
    }
    return true

};