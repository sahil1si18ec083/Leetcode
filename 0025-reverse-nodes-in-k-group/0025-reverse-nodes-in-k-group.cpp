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
    int size(ListNode* head) {
        int l = 0;
        ListNode* current = head;
        while (current) {
            l++;
            current = current->next;
        }
        return l;
    }
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
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
    ListNode* helper(ListNode* head, int k) {
        int n = size(head);
        if (n < k)
            return head;
        if (n == k)
            return reverse(head);

        ListNode* current = head;
        ListNode* prev = NULL;
        for(int i=0;i<k;i++){
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        ListNode* newhead = reverse(head);
        head->next = helper(current, k);
        return newhead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        return helper(head, k);
    }
};