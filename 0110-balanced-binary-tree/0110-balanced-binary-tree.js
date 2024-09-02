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
function height(root) {
    if (root == null) {
        return 0
    }
    return (1 + Math.max(height(root.left), height(root.right)))
}
var isBalanced = function (root) {

    if (root == null) {
        return true
    }

    var left = root.left;
    var right = root.right;

    return (Math.abs(height(left) - height(right)) < 2 && isBalanced(left) && isBalanced(right))



};