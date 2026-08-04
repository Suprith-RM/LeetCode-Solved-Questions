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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        int len = 0;
        ListNode* curr = head;
        while(curr){
            len++;
            curr = curr->next;
        }
        int mid = ceil(len / 2);
        curr = head;
        for(int i = 0; i < mid - 1; ++i){
            curr = curr->next;
        }
        ListNode* temp = curr->next;
        curr->next = nullptr;
        curr = temp;
        curr = reverse(curr);
        ListNode dummy(-1);
        ListNode* newHead = &dummy;
        while(curr || head){
            if(head){
                newHead->next = head;
                head = head->next;
                newHead = newHead->next;
                newHead->next = nullptr;
            }
            if(curr){
                newHead->next = curr;
                curr = curr->next;
                newHead = newHead->next;
                newHead->next = nullptr;
            }
        }
        head = dummy.next;
    }
};