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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* headnext = head->next;
        ListNode* headnextnext = head->next->next;
        headnext->next = NULL;
        ListNode* transformed = swapPairs(headnextnext);
        head->next = transformed;
        headnext->next = head;
        return headnext;

    }
};