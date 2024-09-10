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
 * @param {number} val
 * @param {number} depth
 * @return {TreeNode}
 */
var addOneRow = function (root, val, depth) {
    if (depth==1){
        const node = new TreeNode(val);
        node.left= root;
        return node

    }

    var level = 1;
    const Queue = []
    Queue.push(root)
    let flag = false;

    while (Queue.length > 0) {
        let QueueLength = Queue.length;
        for (let i = 0; i < QueueLength; i++) {
            if (level == depth - 1) {
                flag = true;
                let tempNode = Queue[0];
                Queue.shift();
                let tempNodeleft = tempNode.left;
                let tempNoderight = tempNode.right;
                let l1 = new TreeNode(val);
                let l2 = new TreeNode(val);
                tempNode.left = l1;
                tempNode.right = l2;
                if (tempNodeleft) {
                    l1.left = tempNodeleft

                }
                if (tempNoderight) {
                    l2.right = tempNoderight

                }


            }
            else{


            let temp = Queue[0];


            Queue.shift()
            if (temp.left != null) {
                Queue.push(temp.left)
            }
            if (temp.right != null) {
                Queue.push(temp.right)

            }
            }
        }
        if (flag == true){
            return root
        }
        level++;


    }
    return root;


};