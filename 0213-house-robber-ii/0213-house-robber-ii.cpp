class Solution {
    int helper(vector<int>& nums, int s, int e){
        int prev1 = nums[s];
        int prev2 = max(nums[s], nums[s+1]);
        int result = prev2;
        for(int i = s+2; i <= e; ++i){
            result = max(prev2, prev1 + nums[i]);
            prev1 = prev2;
            prev2 = result;
        }
        return result;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        return(max(helper(nums, 0, n-2), helper(nums, 1, n-1)));
    }
};
