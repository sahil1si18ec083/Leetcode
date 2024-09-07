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
var maxProduct = function (root) {
    const MOD = Math.pow(10, 9) + 7;

    // Function to calculate total sum of all nodes
    function sum(root) {
        if (root == null) return 0;
        return (root.val + sum(root.left) + sum(root.right)) % MOD;
    }

    // Function to calculate max product
    function solve(root, totalsum, max) {
        if (root == null) return 0;

        const lsum = solve(root.left, totalsum, max) % MOD;
        const rsum = solve(root.right, totalsum, max) % MOD;

        let res = lsum + rsum + root.val
        max.val = Math.max((totalsum - res) * res, max.val)
        return res;


        // return (root.val + lsum + rsum) % MOD;
    }

    let totalsum = sum(root) % MOD;  // Calculate total sum of the tree
    let max = { val: 0 };

    solve(root, totalsum, max);  // Find max product

    return max.val % MOD;

};