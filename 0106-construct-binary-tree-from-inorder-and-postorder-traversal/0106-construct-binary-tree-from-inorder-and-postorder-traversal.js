/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} inorder
 * @param {number[]} postorder
 * @return {TreeNode}
 */
var buildTree = function (inorder, postorder) {
    function solve(inorder, postorder, postorderIndex, start, end) {
        if (start > end || postorderIndex.val<0) {
            return null
        }
        var postordervalue = postorder[postorderIndex.val];
        let inorderIndex = -1;
        for (let i = start; i <= end; i++) {
            if (inorder[i] == postordervalue) {
                inorderIndex = i;
                break;

            }
        }
        var root = new TreeNode(postordervalue);
        postorderIndex.val = postorderIndex.val - 1;
         root.right = solve(inorder, postorder, postorderIndex, inorderIndex + 1, end)
        root.left = solve(inorder, postorder, postorderIndex, start, inorderIndex - 1)
       
        
        return root
    }


    var n = inorder.length;
    const postorderIndex = {
        val: n - 1
    }

    return solve(inorder, postorder, postorderIndex, 0, n - 1)



};