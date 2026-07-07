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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        ListNode* temp = head;
        while(temp){
            if(temp->next){
                ListNode* tp = temp->next->next;
                curr->next = temp->next;
                curr = curr->next;
                curr->next = temp;
                curr = curr->next;
                curr->next = nullptr;
                temp = tp;
            } else{
                curr->next = temp;
                temp = temp->next;
            }
        }
        return dummy.next;
    }
};