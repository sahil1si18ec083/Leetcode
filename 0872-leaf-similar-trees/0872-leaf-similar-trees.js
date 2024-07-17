/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {boolean}
 */
var leafSimilar = function (root1, root2) {
    function dfs(root, arr) {
        if (root == null) {
            return;
        }
        // leaf node ko str1 mai append karna hai
        if (root.left == null && root.right == null) {
            arr.push(root.val)

        }
        dfs(root.left, arr) // left ki call
        dfs(root.right, arr) // right ki call
    }
    let leafroot1 = []
    let leafroot2 = []
    dfs(root1, leafroot1)
    dfs(root2, leafroot2)
    console.log({ leafroot1 })
    console.log({ leafroot2 })
    if (leafroot1.length != leafroot2.length) {
        return false
    }
    for (let i = 0; i < leafroot1.length; i++) {
        if (leafroot1[i] != leafroot2[i]) {
            return false
        }
    }
    return true
};