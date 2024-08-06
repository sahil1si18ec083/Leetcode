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
var widthOfBinaryTree = function (root) {
    if(!root) {
        return 0;
    }
    const queue = []
    queue.push({ Node: root, index: 0 });
    let maxlength=0;

    while (queue.length>0) {
        let queuelength = queue.length;
     
        let diff = queue[queue.length-1].index - queue[0].index +1;
        
        if (diff>maxlength){
            maxlength= diff;
        }
        let minValue= queue[0].index;
        for(let i=0;i<queuelength;i++){
            if (queue[i].index<minValue){
                minvalue= queue[i].index
            }
        }
        console.log({minValue})
        for (let i = 0; i < queuelength; i++) {
            let temp = queue[0];

            queue.shift();
            // console.log(temp)
            // console.log(temp.Node)

            if (temp.Node.left != null) {
                queue.push({ Node: temp.Node.left, index: 2* (temp.index-minValue) + 1 })

            }
            if (temp.Node.right != null) {
                queue.push({ Node: temp.Node.right, index: 2* (temp.index-minValue) + 2 })
            }
        }
    }
    return maxlength

};