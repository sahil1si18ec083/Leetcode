/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
        function reverse(head) {
        let current = head;
        let prev = null;
        while (current != null) {
            let temp = current.next
            current.next = prev;
            prev = current;
            current = temp;

        }
        return prev
    }

    let slow = head;
    let fast = head;
    while(fast!= null && fast.next && fast.next.next){
        slow = slow.next;
        fast = fast.next.next;
    }
    let headofright = slow.next;
    slow.next = null;
    let newheadofright = reverse(headofright);

    while(head!=null){
        if (head.val!= newheadofright.val){
            return false
        }
        head = head.next;
        newheadofright = newheadofright.next
    }
    return true
    
};