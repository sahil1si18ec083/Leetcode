/**
 * // Definition for a _Node.
 * function _Node(val, children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {_Node|null} root
 * @return {number[]}
 */
var preorder = function (root) {
    const arr = []
    function helper(arr, root) {
        if (root == null) {
            return;
        }
        arr.push(root.val)

        for (let i = 0; i < root.children.length; i++) {
            helper(arr, root.children[i])
        }

    }

    helper(arr, root)

    return arr

};