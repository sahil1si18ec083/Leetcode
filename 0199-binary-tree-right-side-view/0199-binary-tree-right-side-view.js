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
 * @return {number[]}
 */
function solve(arr,root,level){
    console.log({level})
    if (root==null){
        return
    }
    if (level==arr.length){ // printing root
        arr.push(root.val);
    }
    
    solve(arr,root.right,level+1)  // right part of inorder
    solve(arr,root.left,level+1) // left part of inorder
}  
var rightSideView = function(root) {
    const arr=[]
    let level=0;
    solve(arr,root,level);
    return arr
    
};