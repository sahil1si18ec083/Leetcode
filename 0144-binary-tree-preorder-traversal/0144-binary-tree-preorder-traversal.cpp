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
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> v;
        TreeNode* current = root;
        while (current) {
            if (current->left == NULL) {
                v.push_back(current->val);
                current = current->right;
            } else {
                // current ka left agar null nahi hai toh dekha hai ki left ka
                // right most node null hai ki nahi
                TreeNode* leftNode = current->left;
                while (leftNode->right != NULL && leftNode->right != current) {
                    leftNode = leftNode->right;
                }
                if (leftNode->right == NULL) {
                    v.push_back(current->val);
                    leftNode->right = current;
                    current = current->left;

                } else {
                    leftNode->right = NULL;
                    current= current->right;
                }
            }
        }

        return v;
    }
};