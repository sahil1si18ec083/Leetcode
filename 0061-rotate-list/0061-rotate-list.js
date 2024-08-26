/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var rotateRight = function (head, k) {
    function findlength(head) {
        let length = 0;
        let current = head;
        let prev;
        while (current != null) {
            length++;
            prev = current;
            current = current.next
        }
        return [length, prev];

    }
    let tail = findlength(head)[1]
    const n = findlength(head)[0];
    k = k % n;
    if (k == 0) {
        return head;
    }
    if (head==null || head.next==null){
        return head
    }
    let oldhead = head;
    let newhead = head;
    let newtail = null;
    for (let i = 0; i < n - k; i++) {
        newtail= newhead;
        newhead = newhead.next;
    }
    newtail.next = null;
    tail.next = oldhead;
    return newhead



};