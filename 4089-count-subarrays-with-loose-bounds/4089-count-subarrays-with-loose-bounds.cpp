class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int i = 0, n = nums.size();
        while(i < n){
            int len = 0;
            while(i < n && nums[i] <= maxK && nums[i] >= minK){
                len++, i++;
            } 
            ans += (1LL*len * (len + 1))/2;
            i++;
        }
        return ans;
    }
};