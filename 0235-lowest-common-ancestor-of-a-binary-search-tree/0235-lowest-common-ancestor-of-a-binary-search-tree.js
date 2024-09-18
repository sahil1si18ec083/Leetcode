/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function(root, p, q) {
    let res= null;
    while(root){
        // o(logn) solution 
        if (root.val ==p.val || root.val ==q.val || (p.val<root.val && q.val>root.val) 
        || (q.val<root.val && p.val>root.val)
        
        ){
            res = root
            return res
        }
        else if (p.val<root.val && q.val<root.val){
            root = root.left
        }
        else{
            root = root.right;
        }

    }
    return res
    
};