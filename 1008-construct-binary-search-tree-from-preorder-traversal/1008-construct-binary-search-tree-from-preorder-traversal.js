/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} preorder
 * @return {TreeNode}
 */
var bstFromPreorder = function(preorder) {
    function solve(preorder, preorderIndex,min,max){
        if (preorderIndex.val>=preorder.length ){
            return null;
        }
        if (preorder[preorderIndex.val] <min ||  preorder[preorderIndex.val] >max){
            return null
        }
        const root = new TreeNode(preorder[preorderIndex.val]);
        preorderIndex.val = preorderIndex.val +1;
        root.left = solve(preorder, preorderIndex,min,root.val);
        root.right = solve(preorder, preorderIndex,root.val,max);
        return root

    }


    let preorderIndex={val:0}
    let min=-10000;
    let max=10000;
    return solve(preorder, preorderIndex,min,max)
    
};