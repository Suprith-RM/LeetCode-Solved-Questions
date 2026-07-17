class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }
        int len = n / k;
        int extra = n % k;
        vector<ListNode*> ans(k, nullptr);
        temp = head;
        for (int i = 0; i < k; i++) {
            if (!temp) break;
            ans[i] = temp;
            int currSize = len + (i < extra ? 1 : 0);
            for (int j = 1; j < currSize; j++) {
                temp = temp->next;
            }
            ListNode* nextPart = temp->next;
            temp->next = nullptr;
            temp = nextPart;
        }
        return ans;
    }
};