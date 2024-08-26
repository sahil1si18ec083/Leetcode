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
     function reverse(head) {
       
        let current = head;
        let prev = null;
        while (current != null) {
            let temp = current.next;
            current.next = prev;
            prev = current;
            current = temp;
        }
        return prev
    }
    function findlength(head) {
        let length = 0;
        let current = head;

        while (current != null) {
            length++;

            current = current.next
        }
        return length;

    }
var reverseKGroup = function (head, k) {



    if (k==1 || head==null || head.next==null){
        return head;
    }

    if (k>findlength(head)){
        return head;
    }

    let headtemp = head;
    let tailofLL= head;
    for(let i=0;i<k-1;i++){
        tailofLL= tailofLL.next;

    }
    let next = tailofLL.next;
    tailofLL.next = null;
    let newhead = reverse(headtemp);
    headtemp.next = reverseKGroup(next, k);
    return newhead



};