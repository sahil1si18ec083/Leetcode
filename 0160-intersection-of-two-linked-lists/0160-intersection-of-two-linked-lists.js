/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function (headA, headB) {



    let lengthL1 = 0;
    let lengthL2 = 0;
    let currentA = headA;
    let currentB = headB;
    while (currentA) {
        lengthL1++;
        currentA = currentA.next;
    }
    while (currentB) {
        lengthL2++;
        currentB = currentB.next;
    }

    let difference = lengthL1 - lengthL2;
    currentA = headA;
    currentB = headB;
    console.log(difference)
    if (difference < 0) {
        for (let i = 0; i < Math.abs(difference); i++) {
            currentB = currentB.next;
        }
    }
    else {
        for (let i = 0; i <  Math.abs(difference); i++) {
            currentA = currentA.next;
        }
    }

    while (currentA != currentB) {
        currentA = currentA.next
        currentB = currentB.next
    }
    return currentA;






};