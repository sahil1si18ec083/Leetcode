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
 function gcd(a,b){
    if (a==0){
        return b
    }
    if(b==0){
        return a;
    }
    if (a>b){
        return (gcd(a%b,b))
    }
    return  (gcd(a,b%a))
 }
var insertGreatestCommonDivisors = function(head) {
     // base case for my recursion
    if (head==null || head.next==null){
        return head
    }

    var next = head.next;

    var newNode = new ListNode(gcd(head.val, head.next.val));
    head.next = newNode;
    newNode.next = insertGreatestCommonDivisors(next); 
    // simple recursive  code


    return head

    


};