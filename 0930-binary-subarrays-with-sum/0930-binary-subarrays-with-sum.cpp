class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int n = nums.size(), cnt = 0;
        for(int i = 0; i < n; ++i){
            if(i > 0) nums[i] = nums[i-1] + nums[i];
            
            if(mp.find(nums[i] - goal) != mp.end()){
                cnt += mp[nums[i] - goal];
            }
            mp[nums[i]]++;
        }
        return cnt;
    }
};