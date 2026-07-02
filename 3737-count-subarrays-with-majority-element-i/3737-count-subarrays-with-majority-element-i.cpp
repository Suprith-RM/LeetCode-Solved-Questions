class Solution {
    
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; ++i){
            int candidate = -1;
            int cnt = 0;
            int targetCnt = 0;
            for(int j = i; j < n; j++){
                cnt++;
                if(nums[j] == target){
                    targetCnt++;
                }
                if(2 * targetCnt > cnt) ans++;
            }
        }
        return ans;
    }
};