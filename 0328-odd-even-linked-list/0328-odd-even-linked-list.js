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
    if (head==null || head.next==null || (head.next.next==null)){
        return head
    }
    var even = head;
    var odd = head.next;
    var temp = head.next;
    while (odd  && odd.next) {
        even.next =odd.next;
        even = odd.next;
        odd.next = even.next;
        odd = even.next;
        even.next=null;
    }
    even.next = temp;
    console.log(head.next)
    

    return head


};