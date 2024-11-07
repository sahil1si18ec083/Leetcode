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
    void solve(int &sum, TreeNode* root, int digit) {
        if (root == NULL) {
            return;
        }
        digit = digit * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += digit;
            return ;
            
        }
        // left ki call marunga
        solve(sum, root->left, digit);
        // right ki call marunga
        solve(sum, root->right, digit);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int digit = 0;

        solve(sum, root, digit);
        return sum;
    }
};