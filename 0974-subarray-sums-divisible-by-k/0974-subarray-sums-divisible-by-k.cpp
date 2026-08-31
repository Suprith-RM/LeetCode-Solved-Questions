class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int cumSum = 0, ans = 0, n = nums.size();
        for(int i = 0; i < n; ++i){
            cumSum += nums[i];
            int rem = ((cumSum % k) + k) % k;
            ans += mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};