/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {number}
 */
function getMiddle(head){
 
    let slow = head;
    let fast = head;
    while(fast && fast.next && fast.next.next){
        slow = slow.next;
        fast = fast.next.next
    }
    return slow
} 
function reverse(head){
      let curr = head;
    let prev = null;

    while (curr !== null) {
        let temp = curr.next;
        curr.next = prev;
        prev = curr;
        curr = temp;
    }
    return prev
}
var pairSum = function(head) {
    let middle = getMiddle(head);
    let temp = middle.next;
    middle.next = null;
    let newhead = reverse(temp);
    let maxsum=0
 
    while(head!=null){
        maxsum = Math.max(maxsum , head.val + newhead.val);
        head = head.next;
        newhead = newhead.next


    }

    return maxsum
};