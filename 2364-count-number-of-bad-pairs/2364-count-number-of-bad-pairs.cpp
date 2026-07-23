class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, long long> mp;
        for(int i = 0; i < n; ++i){
            mp[i-nums[i]]++;
        }
        long long ans = 0, sum = 0;
        for(const auto& [key, val]: mp){
            sum += ( val * (val - 1))/2;
        }
        ans = (1LL * n * (1LL * (n-1))) / 2 - sum;
        return ans;
    }
};