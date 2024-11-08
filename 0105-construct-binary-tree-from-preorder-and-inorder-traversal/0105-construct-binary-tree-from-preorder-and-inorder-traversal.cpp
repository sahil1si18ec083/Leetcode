/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
        TreeNode* helper(vector<int>& inorder, vector<int>& preorder, int n,
                     int low, int high, int &preorderindex) {
        if (low > high) {
            return NULL;
        }
        int inorderIndex = -1;
        for (int i = low; i <= high; i++) {
            if (inorder[i] == preorder[preorderindex]) {
                inorderIndex = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(inorder[inorderIndex]);
        preorderindex++;
        root->left = helper(inorder, preorder, n, low, inorderIndex - 1,
                            preorderindex);
        root->right = helper(inorder, preorder, n, inorderIndex + 1, high,
                             preorderindex);
        
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

         int n = inorder.size();
        int low = 0;
        int high = n - 1;
        int preorderindex = 0;

        return helper(inorder, preorder, n, low, high, preorderindex);
        
    }
};