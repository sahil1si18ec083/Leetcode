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
 * @return {number}
 */
var findBottomLeftValue = function(root) {
    let result=null;

    const queue=[]

    queue.push(root)

    while(queue.length){
        let length = queue.length;
        for(let i=0;i<length;i++){
            if(i==0){
                result = queue[0].val
            }
            let temp = queue[0];
            queue.shift()
            if (temp.left){
                queue.push(temp.left)
            }
            if (temp.right){
                queue.push(temp.right)
            }
        }
    }
    return result
    
};