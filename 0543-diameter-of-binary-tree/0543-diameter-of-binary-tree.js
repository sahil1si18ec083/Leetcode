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
function height(root) {
    if (root == null) {
        return 0;
    }
    return (1 + Math.max(height(root.left), height(root.right)))
}
var diameterOfBinaryTree = function (root) {

    if (root == null) {
        return 0;

    }
    let diamterofleft = diameterOfBinaryTree(root.left)
    let diamterofright = diameterOfBinaryTree(root.right)
    return (Math.max(diamterofleft, diamterofright, height(root.left) + height(root.right)))

};