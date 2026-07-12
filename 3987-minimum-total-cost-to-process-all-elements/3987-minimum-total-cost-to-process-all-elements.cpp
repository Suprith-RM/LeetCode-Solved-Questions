class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        int n = nums.size();
        const int MOD = 1e9+7;
        long long sum = 0;
        long long cnt = 0;
        for(int num: nums){
           sum = sum + num;
           cnt += (sum / k);
           sum -= ((sum / k) * k);
        }
        if(sum > 0){
            cnt += (sum + k) / k;
        }
        long long ans;
        if (cnt % 2 == 0)
            ans = ((cnt / 2) % MOD) * ((cnt - 1) % MOD) % MOD;
        else
            ans = (cnt % MOD) * (((cnt - 1) / 2) % MOD) % MOD;
        return (int)ans;
    }
};