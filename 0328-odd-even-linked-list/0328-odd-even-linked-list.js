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
var oddEvenList = function (head) {

    const dummyOdd = new ListNode(-1);
    const dummyEven = new ListNode(-1);
    var currentOdd = dummyOdd
    var currentEven = dummyEven;
    var i=0;
    while (head != null) {
        if (i % 2 == 0) {
            currentOdd.next = head;
            currentOdd = currentOdd.next;

        }
        else {
            currentEven.next = head;
            currentEven = currentEven.next;

        }
        head = head.next;
        i++;
    }
    currentOdd.next = dummyEven.next;
    currentEven.next = null;


    return dummyOdd.next;




};