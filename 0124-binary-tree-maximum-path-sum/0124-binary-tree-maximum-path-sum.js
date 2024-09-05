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
var maxPathSum = function (root) {
    function solve(root, maxsum) {

        if (root == null) {
            return 0;
        }

        var leftsum = solve(root.left, maxsum);
        var rightsum = solve(root.right, maxsum);

        if (leftsum >= 0 && rightsum >= 0) {
            maxsum.value = Math.max(maxsum.value, root.val + leftsum + rightsum)
            return (root.val + Math.max(leftsum, rightsum))
        }
        else if (leftsum < 0 && rightsum < 0) {
            maxsum.value = Math.max(maxsum.value, root.val)
            return root.val

        }
        else{
            maxsum.value = Math.max(maxsum.value, root.val+ Math.max(leftsum, rightsum))
            return (root.val +  Math.max(leftsum, rightsum) )
        }
        
    }

    const maxsum = {
        value: -1001
    }

    solve(root, maxsum);

    return maxsum.value


};