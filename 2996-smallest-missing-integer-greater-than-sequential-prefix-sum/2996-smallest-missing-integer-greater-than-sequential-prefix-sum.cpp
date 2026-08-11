class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int i = 1, n = nums.size(), tar = nums[0];
        unordered_map<int, int> mp;
        for(int j = 0; j < n; ++j) mp[nums[j]]++;
        while(i < n && nums[i] == nums[i-1] + 1) {
            tar += nums[i];
            i++;
        }
        while(mp.count(tar) != 0){
            tar++;
        }
        return tar;
    }
};