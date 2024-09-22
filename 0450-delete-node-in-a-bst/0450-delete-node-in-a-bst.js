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
 * @param {number} key
 * @return {TreeNode}
 */
     function fngetInorderSuccesor(root){
        let val = root.val;
        while(root!=null){
            root= root.left;
            if(root!=null){
                val = root.val;
            }
        }
        return val;
    }
var deleteNode = function (root, key) {

    if (root == null) {
        return root
    }
    if (root.left == null && root.right == null && root.val == key) {
        return null

    }
    if (root.left == null && root.val == key) {
        return root.right
    }
    if (root.right == null && root.val == key) {
        return root.left
    }
    if (root.left && root.right && root.val==key){
        // agar left aur right dono mai children hai then take inorder succesor
        let inordersuccesor = fngetInorderSuccesor(root.right);
        root.val = inordersuccesor;
        root.right = deleteNode(root.right,inordersuccesor)
        return root
    }
    if (key<root.val){
        root.left =deleteNode(root.left,key)
    }
    else{
        root.right =deleteNode(root.right,key)
        
    }
    return root
};