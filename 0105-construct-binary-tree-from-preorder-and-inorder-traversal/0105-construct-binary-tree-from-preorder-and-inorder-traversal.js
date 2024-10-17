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
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function (preorder, inorder) {
    function solve(preorder, inorder, preorderIndex, InorderStart, InorderEnd,n){
        if (InorderStart>InorderEnd ){
            return null;
        }
        const root = new TreeNode(preorder[preorderIndex.index])
        let InorderMiddle;
        for(let i=InorderStart;i<=InorderEnd;i++){
            if (root.val==inorder[i]){
                InorderMiddle=i;
                break;
            }
        }
        preorderIndex.index =  preorderIndex.index +1;
        root.left = solve(preorder, inorder, preorderIndex, InorderStart, InorderMiddle-1,n);
        root.right = solve(preorder, inorder, preorderIndex, InorderMiddle+1, InorderEnd,n);
        return root
    }

    const n = preorder.length;

    let preorderIndex ={index:0}

    let ans= solve(preorder, inorder,preorderIndex, 0,n-1,n)
    return ans

};