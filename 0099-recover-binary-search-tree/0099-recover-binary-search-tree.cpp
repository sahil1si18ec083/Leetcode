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
    void solve(TreeNode* root, TreeNode* &prev, TreeNode* &first,
               TreeNode* &second, TreeNode* &third) {
        // we will apply normal morris traversal

        TreeNode* current = root;
        while (current != NULL) {
            if (current->left == NULL) {
                // push the value
                if (current->val > prev->val) {
                    prev = current;
                } else {
                    if (second == NULL) {
                      
                        second = current;
                        first = prev;
                        prev = current;
                    } else {
                        third = current;
                        prev = current;
                    }
                }
                current = current->right;

            } else {
                TreeNode* leftNode = current->left;
                while (leftNode->right != NULL && leftNode->right != current) {
                    leftNode = leftNode->right;
                }
                if (leftNode->right == current) {
                    if (current->val > prev->val) {
                        prev = current;
                    } else {
                        if (second == NULL) {
                            second = current;
                            first = prev;
                            prev = current;
                        } else {
                            third = current;
                            prev = current;
                        }
                    }

                    leftNode->right = NULL;
                    current = current->right;

                } else {
                    leftNode->right = current;
                    current = current->left;
                }
            }
        }
    }
    void recoverTree(TreeNode* root) {
        TreeNode* prev = new TreeNode(INT_MIN);
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode* third = NULL;
        // cout<<first;
        // cout<<second;
        // cout<<third;
        solve(root, prev, first, second, third);
        if (third == NULL) {
            swap(first->val, second->val); // means swap karnay vale neighbours hai
        } else {
            swap(first->val, third->val);
        }
    }
};