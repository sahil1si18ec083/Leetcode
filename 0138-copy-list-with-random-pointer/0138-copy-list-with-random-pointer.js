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
var copyRandomList = function (head) {
    let copylinkedlisthead = new _Node(-1);
    let currentnodeofcopylinkedlist = copylinkedlisthead;
    let current = head;
    while (current != null) {
        currentnodeofcopylinkedlist.next = new _Node(current.val);
        currentnodeofcopylinkedlist = currentnodeofcopylinkedlist.next
        current = current.next;
    }
    copylinkedlisthead = copylinkedlisthead.next;
  

    const map = new Map()
    current = head;
    currentnodeofcopylinkedlist = copylinkedlisthead;
    while (current != null) {
        map.set(current,currentnodeofcopylinkedlist );
        currentnodeofcopylinkedlist = currentnodeofcopylinkedlist.next;
        current = current.next
    }

    

    currentnodeofcopylinkedlist = copylinkedlisthead;
    current= head;
    while(current){
        // currentnodeofcopylinkedlist.random = map.get( currentnodeofcopylinkedlist).random;
        const random = current.random;
        const myrandom = map.get(random);

        currentnodeofcopylinkedlist.random = myrandom
        currentnodeofcopylinkedlist= currentnodeofcopylinkedlist.next;
        current= current.next;
    }
    return copylinkedlisthead

};