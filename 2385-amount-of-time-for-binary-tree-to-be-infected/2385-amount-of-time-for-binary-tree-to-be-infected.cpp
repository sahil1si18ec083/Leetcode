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
    int amountOfTime(TreeNode* root, int start) {
        int time = 0;
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        unordered_map<TreeNode*, TreeNode*> mp;
        unordered_map<int, TreeNode*> valvsnode;
        q.push(root);
        mp[root] = NULL;


        while (q.size() > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                visited[temp] = false;
                valvsnode[temp->val]= temp;
                q.pop();
                if (temp->left != NULL) {
                    q.push(temp->left);
                    mp[temp->left] = temp;
                }
                if (temp->right != NULL) {
                    q.push(temp->right);
                    mp[temp->right] = temp;
                }
            }
        }
        TreeNode* startnode = valvsnode[start];
        q.push(startnode);
        visited[startnode] = true;
        while (q.size() > 0) {
            int size = q.size();
            bool isinfected = false;
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.front();
                q.pop();
                TreeNode* parent = mp[temp];
                TreeNode* left = temp->left;
                TreeNode* right = temp->right;
                if (parent != NULL && visited[parent] == false) {
                    q.push(parent);
                    visited[parent] = true;
                    isinfected = true;
                }
                if (left != NULL && visited[left] == false) {
                    q.push(left);
                    visited[left] = true;
                    isinfected = true;
                }
                if (right != NULL && visited[right] == false) {
                    q.push(right);
                    visited[right] = true;
                    isinfected = true;
                }
            }
            if (isinfected) {
                time++;
            }
        }
        return time;
    }
};