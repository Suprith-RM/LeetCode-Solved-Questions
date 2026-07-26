class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size(), currWindow = 0;
        for(int i = n - k; i < n; ++i) currWindow += nums[i];
        int maxWindow = currWindow;
        for(int i = 1; i <= k; ++i){
            currWindow += nums[(i + n - 1) % n];
            currWindow -= nums[n-k+i-1];
            maxWindow = max(currWindow, maxWindow);
        }
        return maxWindow;
    }
};