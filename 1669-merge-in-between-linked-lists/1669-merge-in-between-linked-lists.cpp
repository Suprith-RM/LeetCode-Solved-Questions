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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int a_1 = a, b_1 = b - a + 1;
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        curr->next = list1;
        while(a_1--){
            curr = curr->next;
        }
        ListNode* end = curr->next;
        while(b_1--){
            ListNode* nxt = end->next;
            delete(end);
            end = nxt;
        }
        curr->next = list2;
        while(curr->next) curr = curr->next;
        curr->next = end;
        return dummy.next;
    }
};