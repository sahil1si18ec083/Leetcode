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
 * @return {string[]}
 */
var binaryTreePaths = function(root) {
    // this is a similiar problem as path sum 2
    function solve(result,str,root){
        if (root==null){
            return;
        }
        // agar mai leaf node mai pahunch chuka hoon toh root.val ko string mai add kar de aur usss string ko result array mai add kar
        if (root.left==null && root.right==null){
            str= str+ String(root.val);
            result.push(str);

        }
        // ab left ki call mai values ko add kar de string mai
        solve(result,str+String(root.val)+"->",root.left);
        // right ki call mai bi value ko add kar de strig mai
        solve(result,str+String(root.val)+"->",root.right);
    }

    const result=[]
    solve(result,"",root);

    return result;
    
};