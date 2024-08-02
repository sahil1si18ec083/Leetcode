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
 * @return {TreeNode}
 */
var reverseOddLevels = function (root) {
    function solve(left, right, level) {
        if (left == null || right == null) {
            return
        }
        if (level % 2 == 1) {
            let temp = left.val;
            left.val = right.val;
            right.val = temp;

        }

        solve(left.left, right.right, level + 1)
        solve(left.right, right.left, level + 1)
    }
    if (root == null) {
        return root
    }
    var left = root.left;
    var right = root.right;


    solve(left, right, 1);

    return root;

};