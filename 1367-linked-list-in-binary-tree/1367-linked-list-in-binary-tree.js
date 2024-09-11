/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {ListNode} head
 * @param {TreeNode} root
 * @return {boolean}
 */
var isSubPath = function(head, root) {
    function helper(head, root){
        if (head==null){
            return true
        }
        if (root==null){
            return false
        }
        if (root.val == head.val && (helper(head.next, root.left) ||   helper(head.next, root.right) )){
            return true
        }
        return false
    }

    if (root==null){
        return false
    }
    return (helper(head, root) ||  isSubPath( head, root.left) ||  isSubPath(head, root.right))
    
};