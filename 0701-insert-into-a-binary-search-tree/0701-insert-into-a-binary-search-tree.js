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
var insertIntoBST = function(root, val) {
    if(root==null){
        return new TreeNode(val);
    }
    let temp = root;
    while(temp!=null){
        if (temp.val>val){
            if (temp.left==null && temp.right==null){
                temp.left = new TreeNode(val);
                return root
            }
            temp = temp.left
        }
        else{
             if (temp.left==null && temp.right==null){
                temp.right = new TreeNode(val);
                return root
            }
            temp = temp.right

        }
    }

    return root


    
};