class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size(), cnt = 0, maxi = 0;
        bool bigAnamoly = false;
        for(int i = 1; i < n; ++i){
            if(nums[i] < nums[i-1]){
                if(i < n-1 && nums[i + 1] < nums[i-1]) bigAnamoly = true;
                if(bigAnamoly && nums[i] < maxi) return false;
                cnt++;
            }
            else maxi = max(maxi, nums[i-1]);
        }
        return cnt <= 1;
    }
};