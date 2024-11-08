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
    void dfs(TreeNode* root, map<string, vector<TreeNode*>>& myMap) {
        if (root == NULL) {
            return;
        }

        string v = exploresubtree(root, myMap, root);
        myMap[v].push_back(root);
        dfs(root->left, myMap);
        dfs(root->right, myMap);
    }
    string exploresubtree(TreeNode* root, map<string, vector<TreeNode*>>& myMap,
                          TreeNode* start) {
        string s = "";

        dfs_on_subtree(root, s);
        return s;
    }
    void dfs_on_subtree(TreeNode* root, string& s) {
        if (root == NULL) {
            s += "#";
            return;
        }
        int val = root->val;
        s += to_string(val)+"#";

        dfs_on_subtree(root->left, s);

        dfs_on_subtree(root->right, s);
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        map<string, vector<TreeNode*>> myMap;
        vector<TreeNode*> res;

        dfs(root, myMap);

        for (auto i : myMap) {
            cout << i.first << "." << i.second.size() << endl;
            if (i.second.size() > 1) {
                res.push_back(i.second[0]);
            }
        }

        return res;
    }
};