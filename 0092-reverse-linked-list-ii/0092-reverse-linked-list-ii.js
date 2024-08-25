/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} left
 * @param {number} right
 * @return {ListNode}
 */
var reverseBetween = function (head, left, right) {
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
    let count = 1;
    let i;
    let start;
    let end;
    let j;
    let current = head;
    if(head==null || head.next==null || left==right){
        return head
    }
    while (current != null) {
        if (count == left - 1) {
            i = current;

        }
        else if (count == left) {
            start = current;

        }
        else if (count == right) {
            end = current;

        }
        else if (count == right + 1) {
            j = current;

        }
        count++;
        current = current.next
    }
    if (left == 1 && right == count - 1) {
        return reverse(head)
    }
    if (left==1){
        end.next = null;
        let newhead = reverse(start);
        start.next=j;
        return newhead
    }
    if (right==count-1){
        i.next = null;
        let newhead = reverse(start);
        i.next = newhead;
        return head;
    }
    i.next = null;
    end.next = null;
    let reverseofmiddle= reverse(start);
    i.next = reverseofmiddle;
    start.next = j;
    return head

};