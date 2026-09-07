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
    ListNode* reverser(ListNode* head){
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
    ListNode* doubleIt(ListNode* head) {
        head = reverser(head);
        ListNode* temp = head;
        int carry = 0;
        while(temp){
            int digit = temp->val * 2;
            temp->val = (digit + carry) % 10;
            carry = (digit + carry) / 10;
            temp = temp->next;
        }
        head = reverser(head);
        if(carry){
            ListNode* newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        }
        return head;
    }
};