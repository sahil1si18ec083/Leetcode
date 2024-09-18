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
 */
function inorder(root, inorderarr) {
    if (root == null) {
        return;
    }
    inorder(root.left, inorderarr);
    inorderarr.push(root.val);
    inorder(root.right, inorderarr);
}

var BSTIterator = function (root) {


    this.inorderarr = []
    inorder(root, this.inorderarr)

    this.index = 0;
};

/**
 * @return {number}
 */
BSTIterator.prototype.next = function () {
    let val = this.index;
    this.index = this.index+1;
    return this.inorderarr[val]

};

/**
 * @return {boolean}
 */
BSTIterator.prototype.hasNext = function () {
    return (this.index == this.inorderarr.length  ? false : true)

};

/** 
 * Your BSTIterator object will be instantiated and called as such:
 * var obj = new BSTIterator(root)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */