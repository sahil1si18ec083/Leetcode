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
var sumNumbers = function (root) {
    function solve(root, str, res) {
        if (root == null) {
            return
        }
        if (root.left == null && root.right == null) {
            res.val = res.val + Number(str+String(root.val))

        }

        solve(root.left, str+ String(root.val), res)
        solve(root.right, str+ String(root.val), res)



    }

    const res = {
        val: 0
    }
    let str = ""

    solve(root, str, res);


    return res.val;


};