class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size(), ans = INT_MAX;
        for(int i = 1; i < n; ++i){
            nums[i] = nums[i] + nums[i-1];
        }
        for(int i = l; i <= r; ++i){
            for(int j = i-1; j < n; ++j){
                int sum = nums[j];
                if(j >= i)
                    sum -= nums[j-i];
                if(sum > 0)
                    ans = min(ans, sum);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};