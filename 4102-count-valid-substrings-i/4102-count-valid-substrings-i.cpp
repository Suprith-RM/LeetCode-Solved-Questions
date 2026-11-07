class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        int nextBad = n;

        long long ans = 0;

        for (int i = n - 1; i >= 0; --i) {
            if (i + 2 < n && s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
                nextBad = min(nextBad, i + 2);
            }

            ans += nextBad - i;
        }

        return ans;
    }
};