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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>myset;
        for(int i=0;i<nums.size();i++){
            myset.insert(nums[i]);
        }
        ListNode* dummyNode = new ListNode(-1000);
        ListNode* current = dummyNode;
        while(head){
            if(myset.find(head->val)==myset.end()){
                current->next = head;
                current = current->next;

            }
            head = head->next;
           
        }
        current->next= NULL;
        return dummyNode->next;

        
    }
};