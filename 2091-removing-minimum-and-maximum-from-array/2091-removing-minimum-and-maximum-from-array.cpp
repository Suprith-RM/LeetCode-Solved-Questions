class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        for(int k = 0; k < n; ++k){
            if(nums[k] < nums[i]){
                i = k;
            }
            if(nums[k] > nums[j]){
                j = k;
            }
        }
        int R = max(i, j);
        int L = min(i, j);
        int ans = min(R + 1, min(n - L, n - R + L + 1));
        return ans;
    }
};