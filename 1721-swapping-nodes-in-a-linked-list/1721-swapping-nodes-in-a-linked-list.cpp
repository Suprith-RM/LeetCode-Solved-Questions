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
    int lengthOfLL(ListNode* head){
        int cnt = 0;
        while(head){
            head = head->next;
            cnt++;
        }
        return cnt;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int len = lengthOfLL(head);
        ListNode* curr = head;
        ListNode* kth, *nkth;
        for(int i = 1; i <= len; ++i){
            if(i == k) kth = curr;
            if(i == len - k + 1) nkth = curr;
            curr = curr->next;
        }
        swap(kth->val, nkth->val);
        return head;
    }
};