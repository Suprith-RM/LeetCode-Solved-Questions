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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        curr->next = head;
        ListNode* temp = head;
        while(temp){
            int count = k;
            ListNode* end = temp;
            while(end && count > 0){
                end = end->next;
                count--;
            }
            if(count == 0){
                ListNode* last = nullptr;
                for(int i = 0; i < k-1; ++i){
                    ListNode* tp = temp->next;
                    temp->next = tp->next;
                    tp->next = curr->next;
                    curr->next = tp;
                    last = curr->next;
                }
                curr = temp;
            }
            else{
                curr->next = temp;
            }
            temp = end;
        }
        return dummy.next;
    }
};