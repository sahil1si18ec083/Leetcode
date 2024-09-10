/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {number[]}
 */
var nodesBetweenCriticalPoints = function (head) {
    if (head == null || head.next == null || head.next.next == null) {
        return [-1, -1]
    }
    let index = 1;
    const arr = []



    var prev = head;
    var current = head.next;
    while (current && current.next) {
        var  next = current.next;
        if ((current.val < prev.val && current.val < next.val) || (current.val > prev.val && current.val > next.val)) {
            arr.push(index);

        }
        prev = current;
        current = next;
        next = current.next;
        index++;

    }


    if (arr.length < 2) {
        return [-1, -1]
    }

    let minDistace = 1000000
    let maxDistace = arr[arr.length - 1] - arr[0]

    for (let i = 1; i < arr.length; i++) {
        if (arr[i] - arr[i - 1] < minDistace) {
            minDistace = arr[i] - arr[i - 1]
        }
    }


    return [minDistace, maxDistace]






};