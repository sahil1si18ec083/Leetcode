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
    int Length(ListNode* head) {
        int l = 0;
        while (head) {
            l++;
            head = head->next;
        }
        return l;
    }
    ListNode* rotateRight(ListNode* head, int k) {

        int n = Length(head);
        if (n == 0 || k==0)
            return head;
        k = k % n;
        if (k == 0)
            return head;
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* Next = head;
        for (int i = 0; i < k+1; i++) {
            current = current->next;
            prev = Next;
            Next = Next->next;
        }
        for (int i = 0; i < n-2-k; i++) {
            current = current->next;
        }
        current->next = head;
        prev->next = NULL;
        return Next;

    }
};