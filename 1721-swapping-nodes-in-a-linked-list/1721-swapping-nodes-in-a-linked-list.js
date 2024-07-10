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
var swapNodes = function (head, k) {
    function getLength(head) {
        let current = head;
        let length = 0;
        while (current) {
            current = current.next;
            length++;
        }
        return length;
    }

    let count = 0;
    const n = getLength(head);
    let l1;
    let l2;
    let current = head;
    while (current){
       
        count++;
        if (count==k){
            l1= current;
        }
        if (count==n-k+1){
            l2= current;
        }
         current = current.next;

    }

    let temp= l1.val;
    l1.val = l2.val;
    l2.val = temp;
    return head
};