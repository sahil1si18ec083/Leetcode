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
function height(root){
    if (root == null) {
        return 0;
    }
    var leftpart = root.left;
    var rightpart = root.right;

    return (1 + Math.max(height(leftpart), height(rightpart)))
}
var diameterOfBinaryTree = function (root) {
    if (root == null) {
        return 0;
    }

    var leftpart = root.left;
    var rightpart = root.right;
    var leftheight= height(leftpart);
    var rightheight = height(rightpart)
    var totalheight= leftheight+rightheight

    return (Math.max(diameterOfBinaryTree(root.left),totalheight, diameterOfBinaryTree(root.right) ))






};