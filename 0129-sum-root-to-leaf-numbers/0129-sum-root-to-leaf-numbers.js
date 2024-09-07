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
var sumNumbers = function(root) {
    function  solve(total, str, root){
        if (root==null){
            return
        }
        if (root.left==null && root.right==null){
            total.val = total.val + (Number(str)*10 + root.val)
        }
        // left ki call marega toh string mai jodunga
        solve(total, str+String(root.val), root.left)
        // right mai bi toh add karna hai
        solve(total, str+String(root.val), root.right)
    }
    const total={val:0}
    var str=""

    solve(total, str, root)

    return total.val

    
};