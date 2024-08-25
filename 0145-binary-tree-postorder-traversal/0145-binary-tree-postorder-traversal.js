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
 * @return {number[]}
 */
var postorderTraversal = function (root) {
    function solve(res, root) {
        if (root == null) {
            return
        }
        solve(res, root.left);
        solve(res, root.right);
        res.push(root.val)

    }
    const res = []
    solve(res, root)
    return res
};