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
    int len = 0;
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr){
            len++;
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        head = reverse(head);
        stack<int> st;
        vector<int> ans(len);
        while(head){
            while(!st.empty() && st.top() <= head->val) st.pop();
            if(st.empty()) ans[len-1] = 0;
            else ans[len - 1] = st.top();
            st.push(head->val);
            len--;
            head = head->next;
        }
        return ans;
    }
};