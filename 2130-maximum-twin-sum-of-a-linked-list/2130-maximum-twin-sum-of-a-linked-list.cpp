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
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return prev;
    }
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* current = head;
        while (current) {
            ListNode* temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }

        return prev;
    }
    int pairSum(ListNode* head) {
        int maxsum = INT_MIN;
        ListNode* mid = getMiddle(head);
        ListNode* midnext = mid->next;
        mid->next = NULL;
        ListNode* reversed = reverse(midnext);

        while (head && reversed) {
            int sum = head->val + reversed->val;
            if (sum > maxsum) {
                maxsum = sum;
            }
            head = head->next;
            reversed = reversed->next;
        }

        return maxsum;
    }
};