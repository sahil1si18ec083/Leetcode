/**
 * // Definition for a _Node.
 * function _Node(val, left, right, next) {
 *    this.val = val === undefined ? null : val;
 *    this.left = left === undefined ? null : left;
 *    this.right = right === undefined ? null : right;
 *    this.next = next === undefined ? null : next;
 * };
 */

/**
 * @param {_Node} root
 * @return {_Node}
 */
var connect = function(root) {
    const queue=[]
    if (root==null){
        return null;
    }
    queue.push(root)
    while(queue.length>0){
        let queuelength = queue.length;
        for(let i=0;i<queuelength;i++){
            let temp = queue[0];
            queue.shift();
            // no need to populate next pointer for the extreme right node in every row
            if (i!= queuelength-1){
                temp.next = queue[0]
            }
            
            if (temp.left!=null){
                queue.push(temp.left)
            }
             if (temp.right!=null){
                queue.push(temp.right)
            }
        }
    }
    return root
    
};