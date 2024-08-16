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
function solve(root, obj) {
    // inorder traversal
    if (root == null) {
        return
    }
    solve(root.left, obj);

    if (root.val > obj.prev) {
        obj.prev = root.val
    }
    else {
        obj.issorted = false;
    }

    solve(root.right, obj);


}
function validateBST(root, leftrange, rightrange) {
    if (root == null) {
        return true;
    }
    if (root.val > leftrange && root.val < rightrange) {
        return validateBST(root.left, leftrange, root.val) && validateBST(root.right, root.val, rightrange)
    }
    return false
}
var isValidBST = function (root) {

    // let obj ={prev: -Math.pow(2,31)-1, issorted:true};


    // solve(root, obj);

    // return obj.issorted

    let leftrange = -Math.pow(2, 31) - 1;
    let rightrange = Math.pow(2, 31) + 1;

    return validateBST(root, leftrange, rightrange)





};