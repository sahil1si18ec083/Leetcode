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
function inorder(root, inorderarr) {
    if (root == null) {
        return;
    }
    inorder(root.left, inorderarr);
    inorderarr.push(root.val);
    inorder(root.right, inorderarr);
}
var findTarget = function (root, k) {
    const inorderarr = []
    inorder(root, inorderarr);
    console.log(inorderarr)
    let low = 0;
    let high = inorderarr.length - 1;
    while (low < high) {
        if (inorderarr[low] + inorderarr[high] == k) {
            return true;
        }
        else if (inorderarr[low] + inorderarr[high] < k) {
            low++
        }
        else {
            high--;
        }
    }

    return false
};