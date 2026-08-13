class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; ++i){
            mp[nums[i]].push_back(i);
        }
        vector<int> ans;
        for(int q : queries) {
            auto &v = mp[nums[q]];

            if(v.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            int idx = lower_bound(v.begin(), v.end(), q) - v.begin();
            int dist = INT_MAX;
            if(idx > 0) {
                int d = q - v[idx - 1];
                dist = min(dist, d);
                dist = min(dist, n - d);
            }
            if(idx + 1 < v.size()) {
                int d = v[idx + 1] - q;
                dist = min(dist, d);
                dist = min(dist, n - d);
            }
            if(idx == 0) {
                int d = q + n - v.back();
                dist = min(dist, d);
            }

            if(idx == v.size() - 1) {
                int d = v.front() + n - q;
                dist = min(dist, d);
            }

            ans.push_back(dist);
        }
        return ans;
    }
};