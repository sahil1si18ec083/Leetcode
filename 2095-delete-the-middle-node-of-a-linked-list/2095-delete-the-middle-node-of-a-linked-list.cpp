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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prevslow = NULL;
        while (fast && fast->next) {
            prevslow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prevslow == NULL)
            return head->next;
        prevslow->next = slow->next;
        return head;
    }

}
;