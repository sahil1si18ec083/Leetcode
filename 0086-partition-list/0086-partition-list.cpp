/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyNodeleft = new ListNode(INT_MIN);
        ListNode* currentleft = dummyNodeleft;
        ListNode* dummyNodeRight = new ListNode(INT_MIN);
        ListNode* currentRight = dummyNodeRight;
        ListNode* current = head;
        while (current) {
            if (current->val < x) {
                currentleft->next = current;
                currentleft = currentleft->next;

            } else {
                currentRight->next = current;
                currentRight = currentRight->next;
            }
            current = current->next;
        }
        currentleft->next = dummyNodeRight->next;
        currentRight->next = NULL;
        return dummyNodeleft->next ;
    }

};