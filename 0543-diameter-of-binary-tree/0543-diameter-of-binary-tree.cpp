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
    int calculate(TreeNode* root, int& maxval) {
        if (root == NULL) {
            return 0;
        }
        int calculateleftdiameter = calculate(root->left, maxval);
            int calculaterightdiameter = calculate(root->right, maxval);
        maxval = max(maxval, calculateleftdiameter +
                                 calculaterightdiameter);
        return (1+max(calculateleftdiameter , calculaterightdiameter));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int maxval = 0;

        int calc = calculate(root, maxval);

        return maxval;
    }
};