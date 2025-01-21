/**
 * // Definition for a _Node.
 * function _Node(val, next, random) {
 *    this.val = val;
 *    this.next = next;
 *    this.random = random;
 * };
 */

/**
 * @param {_Node} head
 * @return {_Node}
 */
var copyRandomList = function(head) {
    const map = new Map();
    const dummyNode = new  _Node(-1, null, null);
    let currentAddress = dummyNode
    let current = head;
    while(current!=null){
        
        currentAddress.next = new  _Node(current.val, null, null)
        currentAddress= currentAddress.next;
        map.set(current, currentAddress)
        current = current.next;
    }
    console.log(map)
    let newhead = dummyNode.next;
    current = head;
    while(current!= null){
        let b1= map.get(current);
        let randomofcurrent = current.random;
        let b3 = map.get(randomofcurrent);
        b1.random = b3;
        current= current.next


    }
    return dummyNode.next
};