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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {INT_MAX, INT_MIN};
        int temp = -1, first = -1, cnt = 0;
        ListNode* curr = head->next;
        ListNode* prev = head;
        while(curr->next){
            if((curr->val > prev->val && curr->val > curr->next->val) || (curr->val < prev->val && curr->val < curr->next->val)){
                if(first == -1){
                    first = cnt;
                }
                else{
                    if(temp != -1)
                        ans[0] = min(ans[0], cnt - temp);
                    else
                        ans[0] = min(ans[0], cnt - first);
                    ans[1] = max(ans[1], cnt - first);
                    temp = cnt;
                }
            }
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if(ans[0] == INT_MAX)
            return {-1, -1};
        return ans;
    }
};