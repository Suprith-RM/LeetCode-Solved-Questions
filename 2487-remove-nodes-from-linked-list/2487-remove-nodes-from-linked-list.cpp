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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        while(head){
            if(head->val >= curr->val){
                curr->next = head;
                head = head->next;
                curr = curr->next;
                curr->next = nullptr;
            }
            else head = head->next;
        }
        head = reverseList(dummy.next);
        return head;
    }
};