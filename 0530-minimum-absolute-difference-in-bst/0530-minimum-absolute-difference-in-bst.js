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
 * @return {number}
 */
var getMinimumDifference = function (root) {
    function inorder(min, previnordervalue, root) {
        if (root == null) {
            return;
        }
        inorder(min, previnordervalue, root.left)
        if (previnordervalue.val!= 100000 && root.val - previnordervalue.val < min.val) {
            min.val = root.val - previnordervalue.val
        }
        previnordervalue.val = root.val;
        inorder(min, previnordervalue, root.right)

    }
    let min = { val: 100000 }
    let previnordervalue={ val: -100000 }
    inorder(min, previnordervalue, root)

    return min.val;

};