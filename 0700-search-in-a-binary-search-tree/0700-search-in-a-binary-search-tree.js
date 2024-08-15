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
 * @param {number} val
 * @return {TreeNode}
 */
var searchBST = function (root, val) {

    // Iterative Approach
    // while(root!=null){
    //     if (root.val ==val){
    //         return root

    //     }
    //     else if (root.val>val){
    //         root= root.left
    //     }
    //     else{
    //         root= root.right;
    //     }

    // }
    // return null
    if (root == null) {
        return null
    }
    else if (root.val == val) {
        return root
    }
    else if (root.val < val) {
        return searchBST(root.right,val)
    }
    else {
        return searchBST(root.left,val)

    }
};