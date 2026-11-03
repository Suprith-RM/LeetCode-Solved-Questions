class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0, maxi = nums[0], n = nums.size();
        for(int i = 0; i < n; ++i){
            if(nums[i] > maxi){
                ans += i * (nums[i] - maxi);
                maxi = nums[i];
            }
            else ans += maxi - nums[i]; 
        }
        return ans;
    }
};