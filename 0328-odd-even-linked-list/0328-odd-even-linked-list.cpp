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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* current = head;
        ListNode* dummynodeodd = new ListNode(-1);
        ListNode* currentodd = dummynodeodd;
        ListNode* dummynodeeven = new ListNode(-1);
        ListNode* currenteven = dummynodeeven;
        int index=0;
        while(current!= NULL){
            if(index % 2==0){
                currentodd->next = current;
                currentodd = currentodd->next;
            }
            else{
                currenteven->next = current;
                currenteven= currenteven->next;

            }
            current = current->next;
            index++;
        }
        currentodd->next = dummynodeeven->next;
        currenteven->next = NULL;
        return dummynodeodd->next;

    }
};