class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i){
            mp[nums[i]] = i + 1;
        }
        for(int i = 0; i < n; ++i){
            int rem = target - nums[i];
            if(mp.find(rem) != mp.end() && mp[rem] != i + 1){
                int ans = mp[rem];
                vector<int> op = (ans > i + 1) ? vector<int>{i + 1, ans} : vector<int>{ans, i + 1};
                return op;
            }
        }
        return {-1};
    }
};