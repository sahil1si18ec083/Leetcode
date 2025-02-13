/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function(head) {
    if (head==null || head.next==null){
        return head
    }
    var temp = head.next.next;
    var next = head.next;
    next.next = head;
    head.next = swapPairs(temp);
    return next
};