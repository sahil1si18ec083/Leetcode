/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var largestValues = function(root) {
    const queue=[];
    queue.push(root)
    const res=[]
    if (root==null){
        return res
    }
    while(queue.length>0){
        let queueLength = queue.length;
        let max= queue[0].val

        for(let i=0;i<queueLength;i++){
            let temp = queue[0];
            if (temp.val>max){
                max= temp.val
            }
            queue.shift();
            if (temp.left!=null){
                queue.push(temp.left)
            }
            if (temp.right!=null){
                queue.push(temp.right)
            }

        }
        res.push(max)
    }
     return res
};