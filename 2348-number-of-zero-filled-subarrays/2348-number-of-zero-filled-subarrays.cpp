class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int i = 0, n = nums.size();
        long long ans = 0; 
        while (i < n){
            long long cnt = 0;
            while(i < n && nums[i] == 0){
                cnt++;
                i++;
            }
            long long fact = (1LL * cnt * (cnt + 1))/2;
            ans += fact;
            i++;
        }
        return ans;
    }
};