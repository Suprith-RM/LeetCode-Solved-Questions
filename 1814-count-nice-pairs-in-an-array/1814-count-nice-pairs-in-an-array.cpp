class Solution {
    int rev(int num){
        int ans = 0;
        while(num > 0){
            ans = ans * 10 + (num % 10);
            num /= 10;
        }
        return ans;
    }
public:
    int countNicePairs(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, long long> mp;
        long long ans = 0;
        for(int num: nums){
            mp[num - (rev(num))]++;
        }
        for(const auto& [key, val]: mp){
            if (val % 2){
                ans = (ans + (val%MOD * ((val - 1)/2)%MOD))%MOD; 
            }
            else{
                ans = (ans + ((val/2) % MOD * (val - 1) % MOD)) % MOD;
            }
        }
        return (int) ans;
    }
};