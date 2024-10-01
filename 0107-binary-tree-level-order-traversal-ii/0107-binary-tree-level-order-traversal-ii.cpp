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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector <vector <int>> v;
        queue <TreeNode*>q;
        if(root==NULL){
            
            return v;
        }
        q.push(root);
        while(q.size()>0){
            int size = q.size();
            vector <int>row;
            for(int i=0;i<size;i++){
                TreeNode *temp = q.front();
                row.push_back(temp->val);

                q.pop();
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
            v.push_back(row);
        }
       int i=0;
       int j= v.size()-1;
       while(i<=j){
        swap(v[i],v[j]);
        i++;
        j--;
       }

       return v;
        
    }
};