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
 * @param {number} key
 * @return {TreeNode}
 */

function max(root) {
    let val = -1000000;
    while (root != null) {
        val = Math.max(val, root.val);
        root = root.right;
    }
    return val
}
function mydelete (root, key){
    if (root == null) {
        return root
    }
    if (root.val == key) {
        // o child
        if (root.left == null && root.right == null) {
            return null;
        }
        // 1 child
        if (root.left == null && root.right != null) {
            return root.right
        }
        if (root.right == null && root.left != null) {
            return root.left
        }
        // 2 childs
        if (root.left != null && root.right != null) {
            let maxleft = max(root.left);
            root.val = maxleft;
            root.left = mydelete (root.left, maxleft)
        }

    }
    else if (root.val < key) {
        root.right = mydelete (root.right, key)
    }
    else {
        root.left = mydelete (root.left, key)
    }
    return root
}
var deleteNode = function (root, key) {


    

    let newroot = mydelete (root, key)

    return newroot;



};