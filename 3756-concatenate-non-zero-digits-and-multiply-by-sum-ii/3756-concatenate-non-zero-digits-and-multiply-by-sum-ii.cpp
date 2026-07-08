class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        static const int MX = 100001;
        static const int MOD = 1000000007;

        static vector<long long> pow10 = [] {
            vector<long long> p(MX);
            p[0] = 1;
            for (int i = 1; i < MX; i++)
                p[i] = p[i - 1] * 10 % MOD;
            return p;
        }();

        int n = s.size();

        vector<int> sumD(n + 1, 0);     
        vector<int> cntN0(n + 1, 0);     
        vector<long long> prefNum(n + 1, 0); 

        for (int i = 1; i <= n; i++) {
            int d = s[i - 1] - '0';

            sumD[i] = sumD[i - 1] + d;
            cntN0[i] = cntN0[i - 1] + (d > 0);

            if (d)
                prefNum[i] = (prefNum[i - 1] * 10 + d) % MOD;
            else
                prefNum[i] = prefNum[i - 1];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int cnt = cntN0[r + 1] - cntN0[l];
            int sum = sumD[r + 1] - sumD[l];

            long long x =
                (prefNum[r + 1] -
                 prefNum[l] * pow10[cnt] % MOD +
                 MOD) % MOD;

            ans.push_back(x * sum % MOD);
        }

        return ans;
    }
};