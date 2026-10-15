class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; ++i){
            unordered_map<int, int> mp;
            int cnt = 0;
            for(int j = i; j < n; ++j){
                if(mp[nums[j]] == 0)
                    cnt++;
                mp[nums[j]]++;
                ans += (cnt * cnt);
            }
        }
        return ans;
    }
};