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
function dfs(str, isFlag, stringlinkedlist, root) {
    if (root == null) {
        return
    }
    if (root.left == null && root.right == null) {
        const temp = str + String(root.val)
        if (temp.includes(stringlinkedlist)) {
            isFlag.val = true;
        }
    }
    dfs(str + String(root.val) + ".", isFlag, stringlinkedlist, root.left)
    dfs(str + String(root.val) + ".", isFlag, stringlinkedlist, root.right)
}
var isSubPath = function (head, root) {
    var stringlinkedlist = ""
    while (head != null && head.next != null) {
        stringlinkedlist = stringlinkedlist + head.val + ".";
        head = head.next;
    }
    stringlinkedlist = stringlinkedlist + head.val;

    var isFlag = { val: false }
    var str = ""

    dfs(str, isFlag, stringlinkedlist, root)
    return isFlag.val

};