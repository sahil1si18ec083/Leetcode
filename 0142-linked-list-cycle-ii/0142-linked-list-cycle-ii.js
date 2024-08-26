/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var detectCycle = function (head) {
    var slow = head;
    var fast = head;

    var hascycle = false;
    while (fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow == fast) {
            hascycle = true;
            break;

        }

    }
    console.log({ hascycle })
    if (hascycle) {
        slow = head;
        while (slow != fast) {
            slow = slow.next;
            fast = fast.next;


        }
        if (slow == fast) {
            return slow;
        }
    }
    return null
};