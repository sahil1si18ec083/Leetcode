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
 * @return {number[][]}
 */
var verticalTraversal = function (root) {
    if (root == null) {
        return [[]]
    }
    const queue = []
    // h stands for horizontal matlab x coordinate while v stands for y axis matlab root sai vertically kitni distance hai
    queue.push({ h: 0, v: 0, Node: root })
    const map = new Map();
    var level = 0;
    while (queue.length > 0) {
        let queueLength = queue.length;
        level++;

        for (let i = 0; i < queueLength; i++) {
            let temp = queue[0];
            if (!map.has(temp.h)) {
                const innermap = new Map();
                innermap.set(temp.v, [temp.Node.val])
                map.set(temp.h, innermap)
            }
            else {
                const modifiedrMap = map.get(temp.h);
                if (!modifiedrMap.has(temp.v)) {
                    modifiedrMap.set(temp.v, [temp.Node.val]);
                    map.set(temp.h, modifiedrMap)


                }
                else {
                    const arr = modifiedrMap.get(temp.v);
                    arr.push(temp.Node.val);
                    modifiedrMap.set(temp.v, arr);
                    map.set(temp.h, modifiedrMap)

                }



            }
            queue.shift();
            if (temp.Node.left != null) {
                queue.push({ Node: temp.Node.left, h: temp.h - 1, v: level })
            }
            if (temp.Node.right != null) {
                queue.push({ Node: temp.Node.right, h: temp.h + 1, v: level })
            }

        }

        // console.log(queue)

    }
    // console.log(map)
    const newSortedMap = new Map([...map.entries()].sort((a, b) => a[0] - b[0]))

    
    const res = []
    newSortedMap.forEach((value, key) => {
        const map = value;
        const temp = []
        map.forEach((value, key) => {
            const arr=value;
            arr.sort((a,b)=>a-b);
            map[key]= arr;
        })
        map.forEach((value,key)=>{
            for(let i=0;i<value.length;i++){
                temp.push(value[i])
            }
        })
        res.push(temp)

    })
    return res

};