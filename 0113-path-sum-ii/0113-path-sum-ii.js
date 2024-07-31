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
    function solve(root, targetSum, sum, res, arr) {
        if (root == null) {
            return;
        }
        arr.push(root.val);
        sum.val = sum.val + root.val;
        if (root.left == null && root.right == null) {
            const arrcopy = [...arr];
            if (sum.val == targetSum) {
                res.push(arrcopy);
            }
        }
        solve(root.left, targetSum, sum , res, arr) // leftcall
        // arr.pop()
        solve(root.right, targetSum, sum , res, arr) // right call
        arr.pop();
        sum.val = sum.val - root.val;
    }

    const res = [];
    let sum = { val: 0 };
    const arr = []
    solve(root, targetSum, sum, res, arr);
    return res

};