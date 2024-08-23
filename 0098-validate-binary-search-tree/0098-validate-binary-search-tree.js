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
 function validate(root,min,max){
    if (root==null){
        return true
    }
    if (root.val> min && root.val<max){
        return (validate(root.left, min, root.val ) && validate(root.right, root.val,max  ) )
    }

    return false;

 }
var isValidBST = function(root) {
    let min = -Math.pow(2,31)-1;
    let max= Math.pow(2,31);
    return validate(root,min,max);
   

    
};