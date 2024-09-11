/**
 * // Definition for a _Node.
 * function _Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {_Node|null} root
 * @return {number[]}
 */
var postorder = function(root) {
    const arr=[]
    function helper(arr, root){
        if (root==null){
            return;
        }

        for(let i=0;i<root.children.length;i++){
            helper(arr, root.children[i])
        }
        arr.push(root.val)
    }
    
    helper(arr, root)

    return arr

    
};