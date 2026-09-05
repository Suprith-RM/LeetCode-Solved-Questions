class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefMax(n, nums[0]);
        vector<int> suffMin(n, nums[n-1]);
        for(int i = 1; i < n; ++i){
            prefMax[i] = max(prefMax[i-1], nums[i]);
        }
        for(int i = n-2; i >= 0; --i){
            suffMin[i] = min(suffMin[i+1], nums[i]);
        }
        for(int i = 0; i < n; ++i){
            if(prefMax[i] - suffMin[i] <= k) return i;
        }
        return -1;
    }
};