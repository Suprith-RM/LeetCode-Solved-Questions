class Solution {
    const int MOD = 1e9+7;
    long long power(long long x, long long n) {
    long long res = 1;
    x = x % MOD; 
    while (n > 0) {
        if (n & 1) {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD; 
        n >>= 1;       
    }
    return res;
}
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size(), i = 0, j = n-1;
        while(i <= j){
            if(nums[i] + nums[j] <= target){
                ans = (ans % MOD + power(2, j - i) ) % MOD;
                i++;
            }
            else j--;
        }
        return ans;
    }
};