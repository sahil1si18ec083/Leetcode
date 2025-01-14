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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prevslow = NULL;
        for(int i=1;i<=n;i++){
            fast = fast->next;
        }
        if(fast==NULL) return head->next;
        while(fast){
            prevslow= slow;
            slow = slow->next;
            fast = fast->next;

        }
        prevslow->next = slow->next;

        return head;
    
    }
};