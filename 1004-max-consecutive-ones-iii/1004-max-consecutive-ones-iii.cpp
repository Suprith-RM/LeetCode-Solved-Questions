class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, i = 0;
        for(int j = 0; j < n; ++j){
            if(nums[j] == 0) k--;
            while(i <= j && k < 0){
                if(nums[i] == 0) k++;
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};