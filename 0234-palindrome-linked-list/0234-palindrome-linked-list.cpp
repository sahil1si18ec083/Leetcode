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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* current = head;
        ListNode* prev = NULL;
        while (current != NULL) {
            ListNode* temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next==NULL)
            return true;

        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;

        ListNode* reversed = reverseList(slow);

        while (head && reversed) {
            if (head->val != reversed->val) {
                return false;
            }

            reversed = reversed->next;
            head = head->next;
        }
        return true;
    }
};