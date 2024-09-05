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
 * @return {void} Do not return anything, modify root in-place instead.
 */
var flatten = function(root) {
    function solve(arr, root){
        if (root==null){
            return 
        }
        arr.push(root)
        solve(arr, root.left)
        solve(arr, root.right)
    }
    const arr=[];
     solve(arr, root);
     console.log(arr)
     var current = root;
     for(let i=1;i<arr.length;i++){
        current.right= arr[i];
        current.left= null;
        current = arr[i]

     }
     


    
};