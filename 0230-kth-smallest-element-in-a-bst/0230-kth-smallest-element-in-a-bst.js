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
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function (root, k) {
    function dfs(root, k, obj) {
        if (root == null) {
            return
        }
         dfs(root.left, k, obj)
        if (obj.index == k) {
            obj.number = root.val;
            

        }
        obj.index = obj.index + 1;
       
        dfs(root.right, k, obj)

    }

    const obj = {
        index: 1,
        number: 0
    }

    dfs(root, k, obj)
    return obj.number
};