/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {number[]} nums
 * @param {ListNode} head
 * @return {ListNode}
 */
var modifiedList = function(nums, head) {
      if (head==null)  return null;

      const hashset = new Set()
      for(let i=0;i<nums.length;i++){
        hashset.add(nums[i])
      }
      const dummyNode = new ListNode(-1);
      dummyNode.next = head;
      var current = dummyNode;
      while(current && current.next){
        if (hashset.has(current.next.val)){
            current.next = current.next.next;

        }
        else{
            current = current.next;
        }

      }

      return dummyNode.next

};