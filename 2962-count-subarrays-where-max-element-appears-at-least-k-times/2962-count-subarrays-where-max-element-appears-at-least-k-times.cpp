class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = (1LL * n * (n + 1))/2, atmost = 0;
        int maxi = *max_element(nums.begin(), nums.end());
        int cnt = 0, i = 0;
        for(int j = 0; j < n; ++j){
            if(nums[j] == maxi) cnt++;
            while(i < n && cnt > k - 1){
                if(nums[i] == maxi) cnt--;
                i++;
            }
            atmost += j - i + 1;
        }
        ans -= atmost;
        return ans;
    }
};