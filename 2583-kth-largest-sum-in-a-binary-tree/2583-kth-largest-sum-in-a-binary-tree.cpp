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
  public: long long kthLargestLevelSum(TreeNode * root, int k) {
    // Thought process yeh hai ki har level par sum nikalo BFS Sai aur usko min heap 
    // mai dalo kyu ki kth lAargest kay lia toh min heap use hota hai
    queue <TreeNode*> q;
    priority_queue < long long, vector < long long > , greater < long long >> minheap;
    q.push(root);
    while (q.size() > 0) {
      long long qsize = q.size();
      long long levelsum = 0;
      for (long long i = 0; i < qsize; i++) {
        TreeNode * temp = q.front();
        levelsum += temp -> val;
        q.pop();
        if (temp -> left != NULL) {
          q.push(temp -> left);
        }
        if (temp -> right != NULL) {
          q.push(temp -> right);
        }

      }
      minheap.push(levelsum);
      if (minheap.size() > k) {
        minheap.pop();
      }
    }
    return (minheap.size() < k ? -1 : minheap.top());

  }
};