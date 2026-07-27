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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<pair<int, ListNode*>, std::vector<pair<int, ListNode*>>, std::greater<pair<int, ListNode*>>> minheap;
        for(auto& it: lists){
            if(it) minheap.push({it->val, it});
        }
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        while(!minheap.empty()){
            curr->next = minheap.top().second;
            curr = curr->next;
            minheap.pop();
            if(curr->next) minheap.push({curr->next->val, curr->next});
            curr->next = nullptr;
        }
        return dummy.next;
    }
};