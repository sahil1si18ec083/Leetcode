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
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* prev = NULL;
        ListNode* current = head;
        while (current != NULL) {
            ListNode* temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return true;

        ListNode* slow = head;
        ListNode* prev = NULL;

        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* righthead = slow;
        prev->next = NULL;
        ListNode* reversedhead = reverse(righthead);

        while (head != NULL && reversedhead != NULL) {
            if (head->val != reversedhead->val) {

                return false;
            }

            head = head->next;
            reversedhead = reversedhead->next;
        }

        return true;
    }
};