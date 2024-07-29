/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
function printToNode(root, target, arr) {
    
    if (root == null) {
        return false
    }
    arr.push(root.val);
    // console.log(root.val, target)
    if (root.val == target) {
        return true
    }

    if (printToNode(root.left, target, arr) || printToNode(root.right, target, arr)) {
        return true
    }
    // console.log(arr)
    arr.pop()
    return false;
}
var lowestCommonAncestor = function (root, p, q) {
    const arr1 = []
    const arr2 = []

    let ispresentPflag = printToNode(root, p.val, arr1);
    let ispresentQflag = printToNode(root, q.val, arr2);
    let res;
    for(let i=0;i<arr1.length && i<arr2.length;i++){
        if (arr1[i]==arr2[i]){
            res= arr1[i]
        }
    }
    
    return new TreeNode( res)


};