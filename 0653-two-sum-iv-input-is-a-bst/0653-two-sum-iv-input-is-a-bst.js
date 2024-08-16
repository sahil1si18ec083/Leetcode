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
 * @param {number} k
 * @return {boolean}
 */
var findTarget = function (root, k) {
    function solve(root, inorderarr) {
        if (root == null) {
            return;
        }
        solve(root.left, inorderarr);
        inorderarr.push(root.val);
        solve(root.right, inorderarr);

    }
    const inorderarr = []
    solve(root, inorderarr);
    let i = 0;
    let j = inorderarr.length - 1;
    while (i < j) {
        if (inorderarr[i] + inorderarr[j] == k) {
            return true
        }
        else if (inorderarr[i] + inorderarr[j] < k) {
            i++;
        }
        else {
            j--;
        }
    }

    return false
};