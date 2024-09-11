/**
 * // Definition for a _Node.
 * function _Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {_Node|null} root
 * @return {number[][]}
 */
var levelOrder = function(root) {
    const res=[]
    if (root==null) return res
    
    const queue=[];
    queue.push(root);
    while(queue.length){
        const arr=[]
        let queuelength = queue.length;
        for(let i=0;i<queuelength;i++){
            let temp= queue[0];
            arr.push(temp.val)
            queue.shift();
            for(let i=0;i<temp.children.length;i++){
                queue.push(temp.children[i])
            }
        }
        res.push(arr)
    }

    return res

    
};