class Solution {
    int atmost(vector<int>& nums, int k){
        unordered_map<int, int> mp;
        int uniques = 0, j = 0, n = nums.size(), cnt = 0;
        for(int i = 0; i < n; ++i){
            if(mp[nums[i]] == 0){
                uniques++;
            }
            mp[nums[i]]++;
            while(uniques > k){
                mp[nums[j]]--;
                if(mp[nums[j]] == 0) uniques--; 
                j++;
            }
            cnt += i - j + 1;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }
};