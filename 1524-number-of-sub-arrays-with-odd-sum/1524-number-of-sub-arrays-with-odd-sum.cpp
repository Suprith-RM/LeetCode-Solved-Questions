class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long ans = 0;
        long long mod = 1e9 + 7;
        int odd = 0;
        int even = 0;
        int n = arr.size();
        int s = 0;

        for (int i = 0; i < n; i++) {
            s += arr[i];
            if (s % 2 == 0) {
                ans += odd;
                ans %= mod;
                even++;
            } else {
                ans += even + 1;
                ans %= mod;
                odd++;
            }
        }
        return ans % mod;
    }
};