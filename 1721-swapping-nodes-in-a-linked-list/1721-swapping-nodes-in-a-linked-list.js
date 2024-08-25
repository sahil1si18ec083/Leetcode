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
var swapNodes = function(head, k) {
    function getLength(head){
        let length=0;
        let current = head;
        while(current!=null){
            length++;
            current = current.next
        }
        return length;
    }
    const n = getLength(head);
    let kthnode;
    let nminuskthnode;
    let count=1;
    let current = head;
    while(current!=null){
        if (count==k){
            kthnode= current;
        }
        if (count==n-k+1){
            nminuskthnode= current;
        }
        count++;
        current = current.next;
    }
    let a = kthnode.val;
    let b = nminuskthnode.val;
    kthnode.val =b;
    nminuskthnode.val =a;

    return head


    
};