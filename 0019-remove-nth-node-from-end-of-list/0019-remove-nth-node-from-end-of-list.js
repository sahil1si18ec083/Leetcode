/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    let prevslow= null;
    let slow = head;
    let fast = head;
    for(let i=0;i<n;i++){
        fast = fast.next
    }
    if (fast==null){
        // means pahle node hi remove ho gaya hai
        return head.next
    }
    while(fast!=null){
        fast = fast.next;
        prevslow= slow;
        slow = slow.next;
    }
    prevslow.next = slow.next;
    return head
    
};