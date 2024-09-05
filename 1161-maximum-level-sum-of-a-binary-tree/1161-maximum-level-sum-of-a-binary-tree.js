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
var maxLevelSum = function (root) {
    let maxsum = -100001;
    let res;
    let level=1;
    const queue = []
    queue.push(root)
    while (queue.length > 0) {
        let iterator= queue.length;
        let sum=0;
        for(let i=0;i<iterator;i++){
            let temp = queue[0];
            sum= sum + temp.val
            queue.shift();
            if (temp.left!=null){
                queue.push(temp.left)
            }
            if (temp.right!=null){
                queue.push(temp.right)
            }


        }
        if (sum>maxsum){
            maxsum= sum;
            res= level
        }
        level++;


    }
    return res

};