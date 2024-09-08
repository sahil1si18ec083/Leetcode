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
 * @return {number[][]}
 */
var pathSum = function (root, targetSum) {

    function solve(root, targetSum, arr, res, sum) {
        if (root == null) {
            return;
        }
        if (root.left==null && root.right==null &&  root.val + sum == targetSum) {
            const arrcopy = [...arr, root.val];
            res.push(arrcopy)
        }
        solve(root.left, targetSum, [...arr, root.val], res, sum + root.val)
        solve(root.right, targetSum, [...arr, root.val], res, sum + root.val)
    }
    if (root == null) {
        return []
    }

    const res = []
    const arr = []
    var sum = 0;

    solve(root, targetSum, arr, res, sum);

    return res;





};