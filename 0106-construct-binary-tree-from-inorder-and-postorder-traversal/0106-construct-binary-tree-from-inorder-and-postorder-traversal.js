/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} inorder
 * @param {number[]} postorder
 * @return {TreeNode}
 */
var buildTree = function(inorder, postorder) {
    function solve(inorder,postorder,postorderindex,start,end){
        console.log(start,end)
        if (start>end){
            return null;
        }
        // if (start==end){
        //     return new TreeNode(inorder[start])
        // }
        var root = new TreeNode(postorder[postorderindex.val]);
        var rootvalue = root.val;
        var inorderIndex;
        for(let i=start;i<=end;i++){
            if (inorder[i]==rootvalue){
                inorderIndex= i;
                break;

            }
        }
        postorderindex.val = postorderindex.val -1;
        root.right = solve(inorder,postorder,postorderindex,inorderIndex+1,end);
        root.left = solve(inorder,postorder,postorderindex,start,inorderIndex-1);
        
        return root;
    }
    const n = inorder.length;
    const postorderindex={val:n-1};

    return solve(inorder,postorder,postorderindex,0,n-1 );
    
};