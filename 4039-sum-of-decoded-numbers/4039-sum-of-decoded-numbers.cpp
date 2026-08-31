class Solution {
    const int MOD = 1e9 + 7;
    long long safePower(long long a, long long b){
        if(b == 0) return 1;
        long long half = safePower(a, b/2);
        long long res = (half * half) % MOD;
        if (b % 2)
            res = (res * a) % MOD;
        return res;
    }
public:
    int sumDecoded(vector<long long>& nums) {
        long long ans = 0;
        for(long long num: nums){
            long long width = num % 10;
            long long d = 1LL * floor(num / 10);
            long long len = 1LL *log10(d) + 1;
            len = len - width;
            long long mask = safePower(10, len);
            long long y = d % mask;
            long long x = d / mask;
            ans += safePower(x, y);
        }
        return ans % MOD;
    }
};