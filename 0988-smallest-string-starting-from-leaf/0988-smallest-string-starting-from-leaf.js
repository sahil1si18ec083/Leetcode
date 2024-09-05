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
 * @return {string}
 */
var smallestFromLeaf = function (root) {
    const mystr = "abcdefghijklmnopqrstuvwxyz"
    function reverse(s){
        let temp=""
        for(let i=0;i<s.length;i++){
            temp = s[i]+ temp;
        }
        return temp
    }
    function solve(root, arr, str) {
        if (root == null) {
            return
        }
        if (root.left == null && root.right == null) {
            arr.push(reverse(str + mystr[root.val]))


        }

        solve(root.left, arr, str + mystr[root.val])
        solve(root.right, arr, str + mystr[root.val])
    }

    const arr = []
    let str = ""

    solve(root, arr, str)


    // sort karunga 
   
    arr.sort()

    return arr[0]


};