/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         int time = 0;
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        unordered_map<TreeNode*, TreeNode*> mp;
        q.push(root);
        mp[root] = NULL;
         while (q.size() > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                visited[temp] = false;
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
        q.push(target);
        visited[target] = true;
        while (q.size() > 0 && k>0) {
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
            if(time==k){
                break;
            }
        }
        vector<int> res;

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            res.push_back(front->val); 
        }
        return res;
    }
};