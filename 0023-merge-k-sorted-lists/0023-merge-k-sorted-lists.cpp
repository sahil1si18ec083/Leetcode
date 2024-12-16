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
    ListNode* mergeTwoLinkedList(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }
        if (list1->val < list2->val) {
            list1->next = mergeTwoLinkedList(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLinkedList(list2->next, list1);
            return list2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        // my base case
        if (lists.size() == 1) {

            return lists[0];
        }
        vector <ListNode*> right(lists.begin() + 1, lists.end());

        return mergeTwoLinkedList(lists[0], mergeKLists(right));
    }
};