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
var findMode = function(root) {
    const map= new Map();
    function dfs(root, map){
        if (root==null){
            return 
        }
        if (!map.has(root.val)){
            map.set(root.val,1)
        }
        else{
            map.set(root.val, map.get(root.val)+1)
        }
        dfs(root.left, map)
        dfs(root.right, map)
    }
    dfs(root, map)
    console.log(map)
    let max=0;
    map.forEach((value,key)=>{
        if (value>=max){
            max= value;
        }
    })
    console.log(max)
    const res=[]
     map.forEach((value,key)=>{
        console.log(value,key)
        if (value==max){
            
            
            res.push(key)
        }
    })

    return res
};