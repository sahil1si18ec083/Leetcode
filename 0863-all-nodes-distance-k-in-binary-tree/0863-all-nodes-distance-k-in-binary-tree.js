/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} target
 * @param {number} k
 * @return {number[]}
 */

var distanceK = function (root, target, k) {
    class Queue {
        constructor() {
            this.items = {};  // Object to store queue elements
            this.front = 0;   // Index of the front element
            this.back = 0;    // Index of the next empty slot for a new element
        }

        // Adds an element to the back of the queue
        enqueue(element) {
            this.items[this.back] = element;
            this.back++;
        }

        // Removes and returns the element at the front of the queue
        dequeue() {
            if (this.isEmpty()) {
                return undefined; // Return undefined if the queue is empty
            }

            const item = this.items[this.front];
            delete this.items[this.front];
            this.front++;
            return item;
        }

        // Returns the current size of the queue
        length() {
            return this.back - this.front;
        }

        // Checks if the queue is empty
        isEmpty() {
            return this.length() === 0;
        }

        // Returns the element at the front of the queue without removing it
        peek() {
            if (this.isEmpty()) {
                return undefined; // Return undefined if the queue is empty
            }
            return this.items[this.front];
        }
        frontt() {
            return this.items[this.front]; // Alias for the peek method
        }
    }
    // THIS PROBLEM IS SIMILIAR TO BURN A BINARY TREE
    function createChildParentMapping(root, target, childParentMap, targetNode) {
        const queue = new Queue();
        queue.enqueue(root)
        childParentMap.set(root, null)
        while (queue.length() > 0) {
            let length = queue.length();
            for (let i = 0; i < length; i++) {
                let temp = queue.frontt()
                if (temp == target) {
                    targetNode.Node = temp;
                }
                queue.dequeue()
                if (temp.left != null) {
                    queue.enqueue(temp.left)
                    childParentMap.set(temp.left, temp)

                }
                if (temp.right != null) {
                    queue.enqueue(temp.right)
                    childParentMap.set(temp.right, temp)

                }

            }
        }
    }
    const childParentMap = new Map();
    const targetNode = { Node: null }
    createChildParentMapping(root, target, childParentMap, targetNode);
    console.log(targetNode)

    const myQueue = new Queue()

    myQueue.enqueue(targetNode.Node)

    const nodevsVisitedMapping = new Map();
    nodevsVisitedMapping.set(targetNode.Node, true)
    let timer = 0;
    const result=[]
    if(k==0){
        return [target.val]
    }

    while (myQueue.length() > 0) {
        let queuelength = myQueue.length();
        var flag = false;
        for (let i = 0; i < queuelength; i++) {
            let temp = myQueue.frontt();
            myQueue.dequeue();
            if (childParentMap.get(temp) != null && !nodevsVisitedMapping.has(childParentMap.get(temp))) {
                flag = true;
                myQueue.enqueue(childParentMap.get(temp))
                nodevsVisitedMapping.set(childParentMap.get(temp), true)
                
            }
            if (temp.left != null && !nodevsVisitedMapping.has(temp.left)) {
                flag = true;
                myQueue.enqueue(temp.left)
                nodevsVisitedMapping.set(temp.left, true)

            }
            if (temp.right != null && !nodevsVisitedMapping.has(temp.right)) {
                flag = true;
                myQueue.enqueue(temp.right);
                nodevsVisitedMapping.set(temp.right, true)

            }
        }
        if (flag == true) {
            timer++
        }
        if (timer==k){
            console.log(myQueue.length())
            while(myQueue.length()>0){
                result.push(myQueue.frontt().val)
                myQueue.dequeue()

            }
            return result
        }

    }
    return result


};