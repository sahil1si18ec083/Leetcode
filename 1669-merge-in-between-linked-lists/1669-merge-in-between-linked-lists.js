/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {number} a
 * @param {number} b
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeInBetween = function(list1, a, b, list2) {
    var current = list1;
    let count=0;
    let x;
    let y;
    let z;
   
    while(current!=null){
        if (count==a-1){
            x= current;

        }
        if (count==b){
            y= current;

        }
        if (count==b+1){
            z= current;

        }
        current = current.next;
        count++;
    }
    var currentl2 = list2 ;
    while(currentl2 && currentl2.next){
        currentl2= currentl2.next;
    }
    x.next = list2;
    y.next = null;

    currentl2.next = z;
    return list1 
};