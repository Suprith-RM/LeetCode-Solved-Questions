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
        unordered_set<int> st;
        for(int num: nums){
            st.insert(num);
        }
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        ListNode* temp = head;
        while(temp){
            if(st.count(temp->val)){
                temp = temp->next; 
            }
            else{
                curr->next = temp;
                temp = temp->next;
                curr = curr->next;
                curr->next = nullptr;
            }
        }
        return dummy.next;
    }
};