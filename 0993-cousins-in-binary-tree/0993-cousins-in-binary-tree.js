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
 * @param {number} x
 * @param {number} y
 * @return {boolean}
 */
var isCousins = function (root, x, y) {
    const queue = []
    queue.push(root)


    let parentofx = null;
    let parentofy = null;


    while (queue.length > 0) {
        let queueLength = queue.length;
        for (let i = 0; i < queueLength; i++) {
            let temp = queue[0];
            queue.shift()
            if (temp.left) {
                queue.push(temp.left)
                if (temp.left.val == x) {
                    parentofx = temp;

                }
                if (temp.left.val == y) {
                    parentofy = temp;

                }
            }
            if (temp.right) {
                queue.push(temp.right)
                if (temp.right.val == y) {

                    parentofy = temp;

                }
                if (temp.right.val == x) {

                    parentofx = temp;

                }
            }
        }
        if (parentofx && parentofy) {
            if (parentofx != parentofy) {
                return true
            }
            return false
        }
        if (parentofx
            || parentofy) {
            return false
        }
    }


    return false
};