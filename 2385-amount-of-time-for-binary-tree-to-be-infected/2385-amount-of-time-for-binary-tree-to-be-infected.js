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
 * @param {number} start
 * @return {number}
 */
var amountOfTime = function (root, start) {
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
     const childVsParentMap = new Map();
    function getMapping(childVsParentMap, root, start, obj) {
       const queue= new Queue()
        queue.enqueue(root);
        childVsParentMap.set(root, null);

        while (queue.length() > 0) {
            let queueLength = queue.length();
            for (let i = 0; i < queueLength; i++) {
                let temp = queue.frontt();
               
                queue.dequeue();
                if (temp.val == start) {
                    obj.infectedNode = temp;
                }
               
                if (temp.left != null) {
                    queue.enqueue(temp.left);
                    childVsParentMap.set(temp.left, temp);

                }
                if (temp.right != null) {
                    queue.enqueue(temp.right)
                    childVsParentMap.set(temp.right, temp);

                }
            }
        }
    }

   
    let obj = { infectedNode: null };

    getMapping(childVsParentMap, root, start, obj);
   
    var timer = 0;
    const nodevsVisitedMapping = new Map();
    nodevsVisitedMapping.set(obj.infectedNode, true)

    const queue= new Queue()
    queue.enqueue(obj.infectedNode)
    while (queue.length() > 0) {
        let queueLength = queue.length();
         var flag = false;

        for (let i = 0; i < queueLength; i++) {
           
            let temp = queue.frontt()
            queue.dequeue();
            const parentNode = childVsParentMap.get(temp);
            if (parentNode != null &&  !nodevsVisitedMapping.has(parentNode) ){
                queue.enqueue(parentNode);
                nodevsVisitedMapping.set(parentNode, true);
                flag = true;
            }
            if (temp.left != null &&  !nodevsVisitedMapping.has(temp.left)  ) {
                queue.enqueue(temp.left);
                nodevsVisitedMapping.set(temp.left, true);
                flag = true;
            }
            if (temp.right != null &&  !nodevsVisitedMapping.has(temp.right)  ) {
                queue.enqueue(temp.right)
                nodevsVisitedMapping.set(temp.right, true);
                flag = true;

            }
         
        }
           if (flag == true) {
                timer++
            }
    }
    return timer


};