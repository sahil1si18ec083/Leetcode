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
    int sumOfLeftLeaves(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        if (root == NULL) {

            return 0;
        }
        int sum = 0;
        q.push(root);
        while (q.size() > 0) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();

                q.pop();
                if (temp->left != NULL) {
                    q.push(temp->left);
                    if (temp->left->left == NULL && temp->left->right == NULL) {
                        sum += temp->left->val;
                    }
                }
                if (temp->right != NULL) {
                    q.push(temp->right);
                }
            }
        }
        return sum;
    }
};