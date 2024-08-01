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
var preorderTraversal = function (root) {

    function solve(root, res) {
        if (root == null) {
            return;
        }
        res.push(root.val); // pahle push
        solve(root.left, res);
        solve(root.right, res)
    }



    const res = []
    solve(root, res)
    return res

};