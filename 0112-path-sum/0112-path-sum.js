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
 * @param {number} targetSum
 * @return {boolean}
 */
function solve(sum, targetSum, root) {
    if (root==null){
        return false;
    }
    if (root.left == null && root.right == null && sum + root.val == targetSum) {
        return true;
    }
    return (solve(sum + root.val, targetSum, root.left) || solve(sum + root.val, targetSum, root.right))


}
var hasPathSum = function (root, targetSum) {

    var sum = 0;
    return solve(sum, targetSum, root);

};