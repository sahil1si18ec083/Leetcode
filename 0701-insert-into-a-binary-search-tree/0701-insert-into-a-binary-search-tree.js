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
 * @param {number} val
 * @return {TreeNode}
 */
var insertIntoBST = function (root, val) {
    /*
    Recursive Solution
    
    if (root == null) {
        return new TreeNode(val)
    }
    if (root.val < val) {
        root.right = insertIntoBST(root.right, val)

    }
    else {
        root.left = insertIntoBST(root.left, val)

    }
    return root
     */
    let temp = root;
    if (root==null){
        return new TreeNode(val);
    }
    while (temp != null) {
        if (temp.left == null && temp.right == null) {
            if (val < temp.val) {
                temp.left = new TreeNode(val);
                return root
            }
            else {
                temp.right = new TreeNode(val);
                return root
            }
        }
        if (temp.right == null && val > temp.val) {
            temp.right = new TreeNode(val);
            return root
        }
        if (temp.left == null && val < temp.val) {
            temp.left = new TreeNode(val);
            return root
        }
        if (temp.val<val){
            temp=temp.right

        }
        else{
            temp= temp.left
        }
    }
    return root


};