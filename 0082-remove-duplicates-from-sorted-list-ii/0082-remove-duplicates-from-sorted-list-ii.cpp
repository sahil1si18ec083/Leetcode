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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyNode = new ListNode(INT_MIN);
        dummyNode->next = head;
        ListNode* prev = dummyNode;
        ListNode* current = head;
        ListNode* currentprev = dummyNode;

        while (current) {
            ListNode* next = current->next;
            if (current->val != currentprev->val &&
                (next == NULL || next->val != current->val)) {
                prev->next = current;
                prev = current;
            }
            currentprev = current;
            current = current->next;
        }
        prev->next = NULL;

        return dummyNode->next;
    }
};