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
 * @param {TreeNode} subRoot
 * @return {boolean}
 */
function  isSameTree (p, q) {
    if (p == null && q == null) {
        return true;
    }
    if (p == null || q == null) {
        return false;
    }
    return (p.val == q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right))

};
var isSubtree = function (root, subRoot) {
    

    if (root == null && subRoot == null) {
        return true
    }

    if (root == null || subRoot == null) {
        return false
    }


    if (isSameTree(root, subRoot)==true) {
        return true;
    }
    if (isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot)) {
        return true
    }
    return false

};