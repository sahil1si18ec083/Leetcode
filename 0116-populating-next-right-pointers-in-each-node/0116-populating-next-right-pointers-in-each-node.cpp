/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }

        queue<Node*> myQueue;
        myQueue.push(root);
        while (myQueue.size() > 0) {
            int myQueueSize = myQueue.size();
            for (int i = 0; i < myQueueSize; i++) {
                Node* temp = myQueue.front();
                myQueue.pop();
                if (i != myQueueSize - 1) {
                    temp->next = myQueue.front();
                }

                if (temp->left != NULL) {
                    myQueue.push(temp->left);
                }
                if (temp->right != NULL) {
                    myQueue.push(temp->right);
                }
            }
        }
        return root;
    }
};