class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n <= 1) return 0;
        int target = nums[n/2], target2 = nums[n/2 - 1];
        int ans1 = 0, ans2 = 0;
        for(int i = 0; i < n; ++i){
            ans1 += abs(target - nums[i]);
            ans2 += abs(target2 - nums[i]);
        } 
        return min(ans1, ans2);
    }
};