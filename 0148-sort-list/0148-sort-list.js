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
 function getMiddle(head){
        let slow = head;
        let fast = head;
        while(fast!= null && fast.next!=null && fast.next.next!=null){
            slow= slow.next;
            fast = fast.next.next
        }
        return slow
    }
    var mergeTwoLists = function (list1, list2) {
    if (!list1) {
        return list2
    }
    if (!list2) {
        return list1
    }
    if (list1.val < list2.val) {
        list1.next = mergeTwoLists(list1.next, list2)
        return list1;
    }
    else {
        list2.next = mergeTwoLists(list2.next, list1);
        return list2;
    }


};
var sortList = function(head) {
    
    if (head==null || head.next==null){
        return head;
    }

    var middle = getMiddle(head);

    var headofsecondpart = middle.next;

    middle.next = null;

    var l1= head;
    var l2= headofsecondpart;

    return mergeTwoLists(sortList(l1),sortList(l2) )

    
};