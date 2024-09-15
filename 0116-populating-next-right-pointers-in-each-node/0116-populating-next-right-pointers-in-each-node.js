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
    if (root==null){
        return root
    }
    const q=[]
    q.push(root)
    while(q.length>0){
        let qlength = q.length;
        for(let i=0;i<qlength;i++){
            let temp=q[0];
            q.shift();
            if (i!=qlength-1){
                temp.next = q[0]
            }
            if(temp.left){
                q.push(temp.left)
            }
            if (temp.right){
                q.push(temp.right)
            }
        }
    }
    return root
    
};