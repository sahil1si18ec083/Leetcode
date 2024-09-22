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
 * @return {TreeNode}
 */
var balanceBST = function (root) {
    function findInorder(inorder, root) {
        if (root == null) {
            return
        }
        findInorder(inorder, root.left)
        inorder.push(root)
        findInorder(inorder, root.right)

    }
    function helper(inorder,low,high){
        if (low>high){
            return null;
        }
        let mid = Math.floor((low+high)/2);
        const root = inorder[mid];
        root.left= helper(inorder,low,mid-1);
        root.right= helper(inorder,mid+1,high);
        return root

    }
    const inorder = []
    findInorder(inorder, root)
    console.log(inorder)
    const n = inorder.length;

    return helper(inorder,0,n-1)


};