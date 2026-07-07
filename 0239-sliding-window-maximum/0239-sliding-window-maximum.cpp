class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int,int>> dq;
        vector<int> ans;
        for(int i = 0; i < n; ++i){
            if(dq.empty() || nums[i] >= dq.front().first) dq.push_front({nums[i], i});
            else{
                while(!dq.empty() && dq.back().first < nums[i]) dq.pop_back();
                dq.push_back({nums[i], i});
            }
            if(i < k-1) continue;
            while(!dq.empty() && dq.front().second <= i - k) dq.pop_front();
            ans.push_back(dq.front().first);
        }
        return ans;
    }
};