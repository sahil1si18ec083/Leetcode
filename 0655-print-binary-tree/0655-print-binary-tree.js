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
 * @return {string[][]}
 */
var printTree = function (root) {
    function getHeight(root) {
        if (root == null) {
            return 0
        }
        return (1 + Math.max(getHeight(root.left), getHeight(root.right)))
    }
    var height = getHeight(root)-1;
    var m = height +1;
    var n = Math.pow(2,height+1)-1;
    const res=[]
    for(let i=0;i<m;i++){
        const arr=[]
        for(let j=0;j<n;j++){
            arr.push("")
        }
        res.push(arr)
    }

    const queue=[]
    queue.push({Node:root, r:0, c:(n-1)/2})

    while(queue.length>0){
        let queueLength = queue.length;
        for(let i=0;i<queueLength;i++){
            let temp= queue[0];
            res[temp.r][temp.c]= String(temp.Node.val)

            queue.shift()

            if (temp.Node.left!=null){
                 queue.push({Node:temp.Node.left, r:temp.r +1 , c:  temp.c - Math.pow(2, height-temp.r-1)} )
            }
             if (temp.Node.right!=null){
                 queue.push({Node:temp.Node.right, r:temp.r +1 , c:  temp.c + Math.pow(2, height-temp.r-1) })
            }


        }
    }

    return res




};