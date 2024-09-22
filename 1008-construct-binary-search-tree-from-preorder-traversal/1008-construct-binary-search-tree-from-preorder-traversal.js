/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} preorder
 * @return {TreeNode}
 */
var bstFromPreorder = function (preorder) {
    function solve(inorder, preorder, preorderIndex, low, high) {
        // base case
        if (low > high || preorderIndex.val>=n ) {
            return null;

        }
        const rootval = preorder[preorderIndex.val];
        let inorderindex;
        for (let i = low; i <= high; i++) {
            if (inorder[i] == rootval) {
                inorderindex = i;
                break;
            }
        }
        preorderIndex.val= preorderIndex.val +1;
        const root = new TreeNode(rootval);
        root.left =solve(inorder, preorder, preorderIndex, low, inorderindex-1)
        root.right =solve(inorder, preorder, preorderIndex,  inorderindex+1,high)
        return root
    }
    const inorder = [...preorder].sort((a, b) => a - b)
    console.log(inorder)
    console.log(preorder)

    let preorderIndex = { val: 0 }
    var n = inorder.length;
    return solve(inorder, preorder, preorderIndex, 0, n - 1)

};