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
 * @return {ListNode[]}
 */
var splitListToParts = function(head, k) {
    function length(head){
        var l=0;
        while(head!=null){
            l++;
            head = head.next
        }
        return l;
    }
    const n = length(head);
    var extralength = n%k;
    const res = Array(k).fill(null)
    var current = head;
    var j=0;
    var prev = head;
    while(current!=null){
        let lengthoflinkedlist = Math.floor(n/k)+(extralength>0?1:0);

        for(let i=0;i<lengthoflinkedlist-1;i++){
            current= current.next;
        }
        var next = current.next;
      
        current.next = null;
          res[j]= prev;
        

        j++;
        extralength--;
        current = next;
        prev = next

    }
    return res

};