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
 * @param {number} low
 * @param {number} high
 * @return {number}
 */
var rangeSumBST = function (root, low, high) {
    function solve(root, low, high, sum) {
        if (root == null) {
            return;
        }
        solve(root.left, low, high, sum)
        if (root.val >= low && root.val <= high) {
            sum.val = sum.val + root.val

        }
        solve(root.right, low, high, sum)
    }
    let sum = {
        val: 0
    }
    solve(root, low, high, sum)
    return sum.val

};