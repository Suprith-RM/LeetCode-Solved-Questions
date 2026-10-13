class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());
        int i = 0, j = n-1;
        long long ans = 0;
        while(i < j){
                ans -= (nums[i] * nums[i]);
                ans += (nums[j] * nums[j]);
                i++, j--;
        }
        if(i == j)
                ans += (nums[j] * nums[j]);
        return ans;
    }
};