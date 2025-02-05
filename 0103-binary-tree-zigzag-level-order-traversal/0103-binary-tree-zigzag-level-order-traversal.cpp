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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> result;
        bool flag = true;
        if (root == NULL)
            return result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int qsize = q.size();
            vector<int> row(qsize, -1);
            for (int i = 0; i < qsize; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (flag) {
                    row[i] = temp->val;

                } else {
                    row[qsize - 1 - i] = temp->val;
                }

                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            result.push_back(row);
            flag = !flag;
        }
            return result;
    }
};