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
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* slow = head;
          ListNode* prev = NULL;
        ListNode* fast = head;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return prev;
    }
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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;
        ListNode* middle = getMiddle(head);
        ListNode* middlenext = middle->next;
        middle->next = NULL;
        ListNode* reversed = reverseList(middlenext);
        ListNode* dummyNode = new ListNode(-1);
        ListNode* current = dummyNode;
        while (head && reversed) {
            current->next = head;

            head = head->next;
            current = current->next;

            current->next = reversed;
            reversed = reversed->next;
            current = current->next;
        }

        // if (head) {
        //     cout << head->val << endl;
        //     cout << "ffffffffffffffff" << endl;
        //     cout << current->val << endl;
        //     cout << "ffffffffffffffff" << endl;

        //     current->next = head;

        //     head = head->next;
        //     current = current->next;
            
        // }
        if (reversed) {
           
            cout << current->val << endl;
            cout << "ffffffffffffffff" << endl;

            current->next = reversed;

            reversed = reversed->next;
              current = current->next;
        }
        

        cout<<dummyNode->next->val <<"uuu";
        head = dummyNode->next;
    }
};