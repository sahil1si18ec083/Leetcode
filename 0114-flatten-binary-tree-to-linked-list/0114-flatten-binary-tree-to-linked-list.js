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
var flatten = function (root) {
    function dfs(root, preorderarr) {
        if (root == null) {
            return
        }
        preorderarr.push(root)
        dfs(root.left, preorderarr)
        dfs(root.right, preorderarr)
    }

    const preorderarr = []

    dfs(root, preorderarr)

    const head = root;
    let temp = root;
    for(let i=1;i<preorderarr.length;i++){
        temp.right = preorderarr[i];
        temp.left=null;
        temp= preorderarr[i]

    }
    return head

};