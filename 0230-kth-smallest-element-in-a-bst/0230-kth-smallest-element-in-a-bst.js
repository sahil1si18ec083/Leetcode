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

    function solve(obj, root, k) {
        if (root == null) {
            return;
        }

        solve(obj, root.left, k) // inorder mai left ki call
        obj.count = obj.count + 1;
        
        if (obj.count == k) {
           obj.result = root.val
        }
        solve(obj, root.right, k) // inorder mai right ki call


    }
    let obj = {
        count: 0,
        result: -1

    }

    solve(obj, root, k);

    return obj.result


};