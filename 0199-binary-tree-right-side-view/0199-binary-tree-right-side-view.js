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
var rightSideView = function(root) {
    function dfs(arr, root, level){
        if (root==null){
            return ;
        }
        if (level>arr.length){
            arr.push(root.val)
        }
        // right call
        dfs(arr, root.right, level+1);
         // left call
        dfs(arr, root.left, level+1);


    }
    if (root==null){
        return []

    }
    const arr=[]
    var level=1;
    dfs(arr, root, level)
    return arr;
    
};