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
var isCompleteTree = function (root) {
    const queue = []
    queue.push(root)
    var isNullpresent = false;
    while (queue.length > 0) {
        let length = queue.length;
        console.log({ queue })
        for (let i = 0; i < length; i++) {
            let temp = queue[0];
            // console.log(temp.val)
            queue.shift();
            if (temp != null) {
                if (isNullpresent){
                    return  false
                }
                queue.push(temp.left)
                queue.push(temp.right)
            }
            else {
                isNullpresent = true;
            }



        }
    }
    return true

};