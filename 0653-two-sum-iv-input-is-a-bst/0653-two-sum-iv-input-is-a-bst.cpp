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
    void morris_traversal(TreeNode* root, vector<int>& v) {
        // use simple morris travcersal here
        TreeNode *current = root;
        while(current!=NULL){
            if (current->left==NULL){
                v.push_back(current->val);
                current = current->right;
            }
            else {
                // current->left null nahi hai  toh left node kay right mai dekho agar vo right node kisi ko 
                // bi point nahi hai to usko current ko point karvao
                // agar vo current ko point hai toh iska matlab traverse ho chuka , print kar do, aur right mai jao
                TreeNode *leftNode = current->left;
                while(leftNode->right!=NULL && leftNode->right!= current){
                    leftNode = leftNode->right;
                }
                if (leftNode->right==current){
                    v.push_back(current->val);
                    leftNode->right = NULL;
                    current = current->right;
                }
                else{
                    leftNode->right= current;
                    current = current->left;
                }
            }
    }
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        morris_traversal(root, v);
        int i = 0;
        int j = v.size() - 1;
        while (j > i) {
            if (v[i] + v[j] == k) {
                return true;
            } else if (v[i] + v[j] < k) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
};