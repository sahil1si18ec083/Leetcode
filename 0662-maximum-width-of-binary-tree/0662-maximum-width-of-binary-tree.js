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
var widthOfBinaryTree = function(root) {
    var maxlength=0;
    const queue =[]
    queue.push({index:0, Node:root})
    while(queue.length){
        let length = queue.length;
        let diff= queue[length-1].index- queue[0].index +1;
        
        maxlength= Math.max(diff,maxlength )
         let min = queue[0].index;
        for(let i=0;i<length;i++){
           
           
            let temp = queue[0];
            queue.shift()
            if (temp.Node.left!=null){
                queue.push({index: 2*(temp.index-min)+1, Node: temp.Node.left})

            }
            if (temp.Node.right!=null){
                queue.push({index: 2*(temp.index-min)+2, Node: temp.Node.right})
            }
        }


    }
    return maxlength;
    
};