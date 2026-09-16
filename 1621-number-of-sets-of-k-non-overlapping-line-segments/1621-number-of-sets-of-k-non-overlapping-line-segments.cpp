class Solution {
    const int MOD = 1e9 + 7;
    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

public:
    int numberOfSets(int n, int k) {
        long long num = 1, den = 1;
        for (int i = 0; i < (2 * k); ++i) {
            num = (num * (1LL * n + k - 1 - i)) % MOD;
            den = (den * 1LL * (i + 1)) % MOD;
        }
        return num * power(den, MOD - 2) % MOD;
    }
};