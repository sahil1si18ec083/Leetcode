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
function getSum(root) {
    if (root == null) {
        return 0;
    }
    return (root.val + getSum(root.left) + getSum(root.right))
}
function countnodes(root){
    if (root==null){
        return 0;
    }
    return (1+ countnodes(root.left)+ countnodes(root.right))
}
function dfs(root, count) {
    if (root == null) {
        return
    }
    // console.log( getSum(root),countnodes(root), root)
    if (root.val === Math.floor(getSum(root)/countnodes(root))) {
        count.val = count.val + 1;
    }

    dfs(root.left, count)

    dfs(root.right, count)
}
var averageOfSubtree = function (root) {


    let count = {
        val: 0
    }
    dfs(root, count);


    return count.val

};