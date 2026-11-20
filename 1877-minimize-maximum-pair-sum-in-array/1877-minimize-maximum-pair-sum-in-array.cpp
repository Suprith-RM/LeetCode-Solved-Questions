class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0, n = nums.size(); i < n / 2; ++i){
            ans = max(ans, nums[i] + nums[n-(i+1)]);
        }
        return ans;
    }
};