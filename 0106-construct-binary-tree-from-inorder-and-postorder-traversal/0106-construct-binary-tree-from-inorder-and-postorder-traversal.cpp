/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int n,
                     int low, int high, int &postorderindex) {
        if (low > high) {
            return NULL;
        }
        int inorderIndex = -1;
        for (int i = low; i <= high; i++) {
            if (inorder[i] == postorder[postorderindex]) {
                inorderIndex = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(inorder[inorderIndex]);
        postorderindex--;
        root->right = helper(inorder, postorder, n, inorderIndex + 1, high,
                             postorderindex);
        root->left = helper(inorder, postorder, n, low, inorderIndex - 1,
                            postorderindex);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n = inorder.size();
        int low = 0;
        int high = n - 1;
        int postorderindex = n - 1;

        return helper(inorder, postorder, n, low, high, postorderindex);
    }
};