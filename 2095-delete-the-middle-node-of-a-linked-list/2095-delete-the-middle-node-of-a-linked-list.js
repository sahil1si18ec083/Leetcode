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
var deleteMiddle = function(head) {
    if (head==null || head.next==null){
        return null
    }
    if (head.next.next==null){
        head.next =null;
        return head
    }
    //     if (head.next.next.next==null){
    //     head.next =head.next.next
    //     return head
    // }
    let slow = head;
    let  fast = head;
    let prevslow = null;
    while(fast != null && fast.next!=null){
        fast = fast.next.next;
        prevslow= slow;
        slow= slow.next;
    }
   
    prevslow.next = slow.next;
    return  head;
    
};