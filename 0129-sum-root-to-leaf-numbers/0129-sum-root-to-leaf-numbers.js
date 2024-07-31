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
    function solve(root, sum, path) {
        if (root == null) {
            return null;
        }
        if (root.left == null &&  root.right == null) {
           
            sum.value = sum.value + Number(path + String(root.val))
        }
        // left ki call marni padegi
        solve(root.left, sum, path + String(root.val))

        // right ki call marni padegi
        solve(root.right, sum, path + String(root.val))

    }


    let sum = {
        value: 0
    }
    solve(root, sum, "");
    return sum.value


};