/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function (lists) {
    var mergeTwoLists = function (list1, list2) {
   
        if (!list1) {
            return list2
        }
        if (!list2) {
            return list1
        }
        if (list1.val < list2.val) {
            list1.next = mergeTwoLists(list1.next, list2);
            return list1

        }
        else {
            list2.next = mergeTwoLists(list1, list2.next);
            return list2
        }
    };
    function solve(lists) {
        if (lists.length==2) {
            return  mergeTwoLists(lists[0], lists[1])

        }
        return  mergeTwoLists(lists[0], solve(lists.slice(1)))
    }
    const n = lists.length;
    if (n == 0) {
        return null;
    }
    if (n==1){
        return lists[0]
    }

    const res = solve(lists)

    return res;


};