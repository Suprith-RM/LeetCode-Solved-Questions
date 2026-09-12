class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        long long sum = 0, curr = 0;
        int ans = 0, n = nums.size();
        for(int num: nums) 
            sum += num;
        for(int i = n/2 + 1; i < n; ++i)
            curr += nums[i];
        for(int i = 0; i < n; ++i){
            curr += nums[i];
            if(curr > sum - curr) ans++;
            int prev = i - (n/2) + 1;
            if(prev < 0) prev += n;
            curr -= nums[prev];
        }
        return ans;
    }
};