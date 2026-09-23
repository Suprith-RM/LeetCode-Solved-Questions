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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        l1 = reverser(l1);
        l2 = reverser(l2);
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        while(cur1 || cur2 || carry){
            int sum = carry;
            if(cur1){
                sum += cur1->val;
                cur1 = cur1->next;
            }
            if(cur2){
                sum += cur2->val;
                cur2 = cur2->next;
            }   
            carry = sum / 10;
            sum = sum % 10;
            ListNode* newNode = new ListNode(sum);
            curr->next = newNode;
            curr = newNode;
        }
        ListNode* ans = reverser(dummy.next);
        return ans;
    }
};