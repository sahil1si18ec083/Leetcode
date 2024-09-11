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
 * @param {number} target
 * @return {TreeNode}
 */
var removeLeafNodes = function (root, target) {
    if (root == null) {
        return root
    }
    var lefttree = removeLeafNodes(root.left, target);
    var righttree = removeLeafNodes(root.right, target);
    root.left = lefttree;
    root.right = righttree;
    if (root.left == null && root.right == null && root.val == target) {
        return null

    }
return root

};