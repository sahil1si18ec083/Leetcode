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
        console.log("logger")
        obj.issorted = false;
    }
    
    solve(root.right, obj);


}
var isValidBST = function (root) {

    let obj ={prev: -Math.pow(2,31)-1, issorted:true};
    

    solve(root, obj);
   
    return obj.issorted



};