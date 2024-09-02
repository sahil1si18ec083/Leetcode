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
 * @return {boolean}
 */
function height(root, obj) {
    
    if (root == null) {
        return 0
    }
    if (Math.abs(height(root.left,obj) - height(root.right,obj)) > 1) {
       obj.val = false;   // Update obj.val to false if the tree is unbalanced
        return null;
       
        // obj.val = false;
        return null

    }
    return (1 + Math.max(height(root.left,obj), height(root.right,obj)))
}
var isBalanced = function (root) {


    var obj = { val: true }
    var h1 = height(root, obj)

    return obj.val







};